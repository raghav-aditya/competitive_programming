/*
 * ======================================================
 *                  TIC TAC TOE SYSTEM (LLD)
 * ======================================================
 *
 * Fixed 3×3 board version, using Lombok for brevity.
 * Multiple concurrent games can be played simultaneously.
 */

import lombok.*;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

// ======================================================
// ENUMS
// ======================================================

enum Symbol {
    X, O, EMPTY
}

enum GameStatus {
    IN_PROGRESS, DRAW, WIN
}

// ======================================================
// ENTITY: Player
// ======================================================

@Data
@NoArgsConstructor
@AllArgsConstructor
class Player {
    private String playerId = UUID.randomUUID().toString();
    private String name;
    private Symbol symbol;
}

// ======================================================
// ENTITY: Board (Fixed 3x3)
// ======================================================

@Data
@NoArgsConstructor
@AllArgsConstructor
class Board {
    private static final int SIZE = 3;
    private Symbol[][] grid = new Symbol[SIZE][SIZE];

    {
        for (int i = 0; i < SIZE; i++) Arrays.fill(grid[i], Symbol.EMPTY);
    }

    public boolean placeSymbol(int row, int col, Symbol s) {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return false;
        if (grid[row][col] != Symbol.EMPTY) return false;
        grid[row][col] = s;
        return true;
    }

    public void printBoard() {
        for (Symbol[] row : grid) {
            for (Symbol c : row)
                System.out.print((c == Symbol.EMPTY ? "-" : c) + " ");
            System.out.println();
        }
        System.out.println();
    }

    public boolean isFull() {
        for (Symbol[] row : grid)
            for (Symbol c : row)
                if (c == Symbol.EMPTY) return false;
        return true;
    }

    public Symbol[][] getGrid() {
        return grid;
    }
}

// ======================================================
// GAME INSTANCE
// ======================================================

class TicTacToeGame implements Runnable {
    private final String gameId = UUID.randomUUID().toString();
    private final Player player1;
    private final Player player2;
    private final Board board = new Board();
    private Player currentPlayer;
    private GameStatus status = GameStatus.IN_PROGRESS;
    private Player winner;

    public TicTacToeGame(Player p1, Player p2) {
        this.player1 = p1;
        this.player2 = p2;
        this.currentPlayer = p1;
    }

    @Override
    public void run() {
        System.out.println("Game " + gameId + " started between " +
                player1.getName() + " and " + player2.getName());

        Scanner scanner = new Scanner(System.in);

        while (status == GameStatus.IN_PROGRESS) {
            board.printBoard();
            System.out.println(currentPlayer.getName() + " (" + currentPlayer.getSymbol() + "), enter row and column (0-based): ");

            int row = scanner.nextInt();
            int col = scanner.nextInt();

            if (!board.placeSymbol(row, col, currentPlayer.getSymbol())) {
                System.out.println("Invalid move, try again!");
                continue;
            }

            if (checkWin(currentPlayer.getSymbol())) {
                status = GameStatus.WIN;
                winner = currentPlayer;
                board.printBoard();
                System.out.println("Winner: " + winner.getName());
                break;
            }

            if (board.isFull()) {
                status = GameStatus.DRAW;
                board.printBoard();
                System.out.println("Game is a draw!");
                break;
            }

            switchPlayer();
        }
    }

    private void switchPlayer() {
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    private boolean checkWin(Symbol s) {
        Symbol[][] g = board.getGrid();

        for (int i = 0; i < 3; i++) {
            if ((g[i][0] == s && g[i][1] == s && g[i][2] == s) ||
                (g[0][i] == s && g[1][i] == s && g[2][i] == s))
                return true;
        }

        return (g[0][0] == s && g[1][1] == s && g[2][2] == s) ||
               (g[0][2] == s && g[1][1] == s && g[2][0] == s);
    }

    public String getGameId() { return gameId; }
}

// ======================================================
// GAME MANAGEMENT SERVICE
// ======================================================

class TicTacToeManagementService {
    private final Map<String, Thread> activeGames = new ConcurrentHashMap<>();

    public String createAndStartGame(Player p1, Player p2) {
        TicTacToeGame game = new TicTacToeGame(p1, p2);
        Thread thread = new Thread(game);
        thread.start();
        activeGames.put(game.getGameId(), thread);
        return game.getGameId();
    }

    public void listActiveGames() {
        System.out.println("Active Games: " + activeGames.keySet());
    }

    public void stopGame(String gameId) {
        Thread t = activeGames.get(gameId);
        if (t != null) t.interrupt();
        activeGames.remove(gameId);
        System.out.println("Game " + gameId + " stopped.");
    }
}

// ======================================================
// DRIVER
// ======================================================

public class TicTacToeSystem {
    public static void main(String[] args) {
        TicTacToeManagementService manager = new TicTacToeManagementService();

        Player p1 = new Player(UUID.randomUUID().toString(), "Alice", Symbol.X);
        Player p2 = new Player(UUID.randomUUID().toString(), "Bob", Symbol.O);

        String game1 = manager.createAndStartGame(p1, p2);

        Player p3 = new Player(UUID.randomUUID().toString(), "Charlie", Symbol.X);
        Player p4 = new Player(UUID.randomUUID().toString(), "Diana", Symbol.O);

        String game2 = manager.createAndStartGame(p3, p4);

        manager.listActiveGames();
    }
}
