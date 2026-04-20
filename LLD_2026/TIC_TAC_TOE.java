import java.util.*;

class TicTacToeLLD {

    // -------- Player --------
    static class Player {
        int id;        // 1 or -1
        char symbol;   // 'X' or 'O'

        Player(int id, char symbol) {
            this.id = id;
            this.symbol = symbol;
        }
    }

    // -------- Board --------
    static class Board {
        int n;
        char[][] grid;

        Board(int n) {
            this.n = n;
            grid = new char[n][n];
            for (char[] row : grid) Arrays.fill(row, '-');
        }

        boolean isValidMove(int row, int col) {
            return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] == '-';
        }

        void placeMove(int row, int col, char symbol) {
            grid[row][col] = symbol;
        }

        void printBoard() {
            for (char[] row : grid) {
                for (char c : row) System.out.print(c + " ");
                System.out.println();
            }
            System.out.println();
        }
    }

    // -------- Game --------
    static class Game {
        Board board;
        Player[] players;
        int currentPlayerIndex;

        int[] rows;
        int[] cols;
        int diag = 0;
        int antiDiag = 0;

        boolean gameOver = false;

        Game(int n) {
            board = new Board(n);
            players = new Player[]{
                new Player(1, 'X'),
                new Player(-1, 'O')
            };
            currentPlayerIndex = 0;

            rows = new int[n];
            cols = new int[n];
        }

        public boolean makeMove(int row, int col) {
            if (gameOver) {
                System.out.println("Game already finished.");
                return false;
            }

            if (!board.isValidMove(row, col)) {
                System.out.println("Invalid move.");
                return false;
            }

            Player player = players[currentPlayerIndex];
            board.placeMove(row, col, player.symbol);

            // Update counters
            rows[row] += player.id;
            cols[col] += player.id;

            if (row == col) diag += player.id;
            if (row + col == board.n - 1) antiDiag += player.id;

            // Check win
            if (Math.abs(rows[row]) == board.n ||
                Math.abs(cols[col]) == board.n ||
                Math.abs(diag) == board.n ||
                Math.abs(antiDiag) == board.n) {

                gameOver = true;
                System.out.println("Player " + player.symbol + " wins!");
                return true;
            }

            // Switch player
            currentPlayerIndex = 1 - currentPlayerIndex;
            return true;
        }

        public void printBoard() {
            board.printBoard();
        }
    }

    // -------- Driver --------
    public static void main(String[] args) {
        Game game = new Game(3);

        game.makeMove(0, 0); // X
        game.makeMove(0, 1); // O
        game.makeMove(1, 1); // X
        game.makeMove(0, 2); // O
        game.makeMove(2, 2); // X wins

        game.printBoard();
    }
}