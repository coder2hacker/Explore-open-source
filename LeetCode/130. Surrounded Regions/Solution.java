class Solution {
    int row;
    int col;
    
    public void solve(char[][] board) {
        row = board.length;
        col = board[0].length;

        // top and bottom boarder
        // dfs from each col
        for(int i = 0; i < col; i++) {
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }
        
        // check left and right border
        // dfs from each row
        for(int i = 0; i < row; i++) {
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
    }
    
    int[][] directions = new int[][]{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    public void dfs(char[][] board, int i , int j) {
        if ((i < 0 || j < 0 || i >= row || j >= col) // out of bounds
            || board[i][j] == 'T' // already visited
            || board[i][j] != 'O') { // not connected to an O
            return;
        }
        
        board[i][j] = 'T';
        
        // dfs neighbours
        for(int[] dir : directions) {
            dfs(board, dir[0] + i, dir[1] + j);
        }
    }
    
}
