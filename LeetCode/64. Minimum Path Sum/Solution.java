// https://leetcode.com/problems/minimum-path-sum/

class Solution {
    public int minPathSum(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int countRows = 0, countCols = 0;
        while (countRows < r || countCols < c) {
            for (int i = 0; i < countRows; i++) {
                insertMinSum(i, countCols, grid);
            }
            for (int i = 0; i < countCols; i++) {
                insertMinSum(countRows, i, grid);
            }

            insertMinSum(countRows, countCols, grid);

            countCols++;
            countRows++;
        }
        return grid[r - 1][c - 1];
    }

    private void insertMinSum(int row, int col, int[][] grid) {
        if (cellExists(row, col ,grid)) {
            if (cellExists(row - 1, col, grid) && cellExists(row, col - 1, grid)) {
                int val = grid[row][col];
                grid[row][col] = Math.min(grid[row - 1][col] + val, grid[row][col - 1] + val);
            } else if (cellExists(row - 1, col, grid)) {
                grid[row][col] += grid[row - 1][col];
            } else if (cellExists(row, col - 1, grid)) {
                grid[row][col] += grid[row][col - 1];
            }
        }
    }

    private boolean cellExists(int row, int col, int[][] array) {
        return (row <= array.length - 1 && row >= 0) && (col <= array[0].length - 1 && col >= 0);
    }
}
