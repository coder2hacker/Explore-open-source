// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
    public int[][] generateMatrix(int n) {
      int[][] result = new int[n][n];
        int k = 0;
        int rowStart = 0, rowEnd = n;
        int colStart = 0, colEnd = n;
        while (k < n * n) {

            // right
            for(int i = rowStart; k < n * n && i < colEnd; i ++) {
                result[rowStart][i] = ++ k;
            }
            rowStart ++;

            // down
            for(int i = rowStart; k < n * n && i < rowEnd; i ++) {
                result[i][colEnd - 1] = ++ k;
            }
            colEnd --;

            // left
            for(int i = colEnd - 1; k < n * n && i >= colStart; i --) {
                result[rowEnd - 1][i] = ++ k;
            }
            rowEnd --;

            // up
            for(int i = rowEnd - 1; k < n * n && i >= rowStart; i --) {
                result[i][colStart] = ++ k;
            }
            colStart ++;

        }
        return result;
    }
}
