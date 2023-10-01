class Solution {
    public void solveSudoku(char[][] board) {
        fill(board);
    }
    
    public boolean fill(char[][] mat){
        
        for(int i =0;i<9;i++){
            for(int j = 0;j<9;j++){
                
                if(mat[i][j]=='.'){
                    
                    for(char c = '1';c<='9';c++){
                        if(isValid(mat,c, i, j)){
                            mat[i][j] = c;
                            // System.out.println(mat[i][j]);
                            if(fill(mat)) return true;
                            else{
                                mat[i][j] = '.';
                            }
                        }
                    }
                    return false;
                    
                }
            }
        }
        return true;
        
    }
   
    
    public boolean isValid(char[][] board,char c,int row, int col){
       
        for (int i = 0; i < 9; i++) {
            
              if (board[i][col] == c)
                return false;

              if (board[row][i] == c)
                return false;

              if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
            
        }
        
        return true;
    }
    
    
    
}
