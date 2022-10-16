// https://leetcode.com/problems/sudoku-solver/

class Solution1 {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) {
            throw new IllegalArgumentException("Input is invalid");
        }

        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxes = new int[9];
        List<int[]> blanks = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                // To Blanks List
                if (c == '.') {
                    blanks.add(new int[] { i, j });
                    continue;
                }

                // Check for Invalid Chars
                if (c < '1' || c > '9') {
                    throw new IllegalArgumentException("Invalid sudoku board");
                }

                int b = 3 * (i / 3) + (j / 3);
                int mask = 1 << (c - '1');

                // Check for unsolvable board
                if (((rows[i] & mask) != 0) || ((cols[j] & mask) != 0) || ((boxes[b] & mask) != 0)) {
                    throw new IllegalArgumentException("Invalid sudoku board");
                }

                // Add the cell to rows, cols and boxes.
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[b] |= mask;
            }
        }

        if (!solveSudokuHelper(board, rows, cols, boxes, blanks, 0)) {
            throw new RuntimeException("Input sudoku does not have a valid solution");
        }
    }

    private boolean solveSudokuHelper(char[][] board, int[] rows, int[] cols, int[] boxes, List<int[]> blanks,
            int idx) {
        if (idx == blanks.size()) {
            return true;
        }

        int[] cell = blanks.get(idx);
        int i = cell[0];
        int j = cell[1];
        int b = 3 * (i / 3) + (j / 3);

        for (char c = '1'; c <= '9'; c++) {
            int mask = 1 << (c - '1');

            // Check if the number already used in row, column and sub-box.
            if (((rows[i] & mask) != 0) || ((cols[j] & mask) != 0) || ((boxes[b] & mask) != 0)) {
                continue;
            }

            // Add the cell to rows, cols and boxes.
            rows[i] |= mask;
            cols[j] |= mask;
            boxes[b] |= mask;
            board[i][j] = c;

            if (solveSudokuHelper(board, rows, cols, boxes, blanks, idx + 1)) {
                return true;
            }

            // Backtrack
            // Remove the cell to rows, cols and boxes.
            rows[i] &= ~mask;
            cols[j] &= ~mask;
            boxes[b] &= ~mask;
        }

        return false;
    }
}
