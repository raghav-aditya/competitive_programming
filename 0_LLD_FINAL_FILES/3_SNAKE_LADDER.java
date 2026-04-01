/*
 * ======================================================
 *          SNAKE AND LADDER SYSTEM (LOMBOK VERSION)
 * ======================================================
 *
 * Clean, concurrent, and concise version using Lombok.
 * Multiple games can run simultaneously.
 */

import lombok.*;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ThreadLocalRandom;

// ======================================================
// ENTITY: Player
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
class Player {
    private String playerId = UUID.randomUUID().toString();
    private String name;
    private int position = 0;
}

// ======================================================
// ENTITY: Snake
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
class Snake {
    private int head;
    private int tail;

    public Snake(int head, int tail) {
        if (tail >= head) throw new IllegalArgumentException("Invalid snake configuration");
        this.head = head;
        this.tail = tail;
    }
}

// ======================================================
// ENTITY: Ladder
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
class Ladder {
    private int start;
    private int end;

    public Ladder(int start, int end) {
        if (start >= end) throw new IllegalArgumentException("Invalid ladder configuration");
        this.start = start;
        this.end = end;
    }
}

// ======================================================
// ENTITY: Dice
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
class Dice {
    private int sides = 6;

    public int roll() {
        return ThreadLocalRandom.current().nextInt(1, sides + 1);
    }
}

// ======================================================
// ENTITY: Board
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
class Board {
    private int size;
    private List<Snake> snakes = new ArrayList<>();
    private List<Ladder> ladders = new ArrayList<>();

    public int getNewPosition(int position) {
        for (Snake s : snakes)
            if (s.getHead() == position) {
                System.out.println("Bitten by snake: " + s.getHead() + " → " + s.getTail());
                return s.getTail();
            }

        for (Ladder l : ladders)
            if (l.getStart() == position) {
                System.out.println("Climbed ladder: " + l.getStart() + " → " + l.getEnd());
                return l.getEnd();
            }

        return position;
    }
}

// ======================================================
// GAME INSTANCE
// ======================================================

@Data
class SnakeAndLadderGame implements Runnable {
    private final String gameId = UUID.randomUUID().toString();
    private final Board board;
    private final Dice dice;
    private final Queue<Player> players;
    private boolean finished;

    public SnakeAndLadderGame(Board board, List<Player> playerList, Dice dice) {
        this.board = board;
        this.dice = dice;
        this.players = new LinkedList<>(playerList);
        this.finished = false;
    }

    @Override
    public void run() {
        System.out.println("Game " + gameId + " started with " + players.size() + " players.");

        while (!finished) {
            Player current = players.poll();
            if (current == null) continue;

            int roll = dice.roll();
            int newPos = current.getPosition() + roll;

            if (newPos > board.getSize()) {
                System.out.println(current.getName() + " rolled " + roll + " but overshoots.");
                players.offer(current);
                continue;
            }

            newPos = board.getNewPosition(newPos);
            current.setPosition(newPos);

            System.out.println(current.getName() + " rolled " + roll + " → moved to " + newPos);

            if (newPos == board.getSize()) {
                System.out.println("Player " + current.getName() + " wins game " + gameId);
                finished = true;
                break;
            }

            players.offer(current);

            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

// ======================================================
// GAME MANAGEMENT SERVICE
// ======================================================

class SnakeAndLadderManagementService {
    private final Map<String, Thread> runningGames = new ConcurrentHashMap<>();

    public String createAndStartGame(List<Player> players, List<Snake> snakes, List<Ladder> ladders, int boardSize) {
        Dice dice = new Dice(6);
        Board board = new Board(boardSize, snakes, ladders);
        SnakeAndLadderGame game = new SnakeAndLadderGame(board, players, dice);

        Thread thread = new Thread(game);
        thread.start();

        runningGames.put(game.getGameId(), thread);
        return game.getGameId();
    }

    public void stopGame(String gameId) {
        Thread t = runningGames.get(gameId);
        if (t != null) t.interrupt();
        runningGames.remove(gameId);
        System.out.println("Game " + gameId + " stopped.");
    }

    public void listActiveGames() {
        System.out.println("Active Games: " + runningGames.keySet());
    }
}

// ======================================================
// DRIVER
// ======================================================

public class SnakeAndLadderSystem {
    public static void main(String[] args) throws InterruptedException {
        SnakeAndLadderManagementService manager = new SnakeAndLadderManagementService();

        List<Player> game1Players = List.of(
            Player.builder().name("Alice").build(),
            Player.builder().name("Bob").build()
        );

        List<Player> game2Players = List.of(
            Player.builder().name("Charlie").build(),
            Player.builder().name("Diana").build()
        );

        List<Snake> snakes = List.of(
            new Snake(14, 7),
            new Snake(31, 5),
            new Snake(47, 15)
        );

        List<Ladder> ladders = List.of(
            new Ladder(3, 22),
            new Ladder(8, 26),
            new Ladder(20, 41)
        );

        String game1 = manager.createAndStartGame(game1Players, snakes, ladders, 50);
        String game2 = manager.createAndStartGame(game2Players, snakes, ladders, 50);

        Thread.sleep(6000);
        manager.listActiveGames();
    }
}
