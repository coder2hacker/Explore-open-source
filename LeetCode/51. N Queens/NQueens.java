class Solution {
    
    public void solveHelper(char[][] mat, int row, int n,
                           List<List<String>> ans,int [] checkColumn,
                            int[] checkLeftDiagonal,int[] checkRightDiagonal){
        //base case
        if(row==n){
            //add into ans;
            //matrix is ready
            List<String> temp = new ArrayList<>();
            for(int i =0;i<n;i++){
                String s = new String(mat[i]);
                temp.add(new String(s));
            }
            ans.add(new ArrayList(temp));
          
        }
        
        for(int col = 0;col<n;col++){  
            if(checkColumn[col]==0
               && checkLeftDiagonal[(n-1)+(col-row)]==0
                && checkRightDiagonal[row+col]==0){
                
                checkColumn[col] = 1;
                checkLeftDiagonal[(n-1)+(col-row)]=1;
                checkRightDiagonal[col+row] = 1;
                
                mat[row][col] = 'Q';
                
                solveHelper(mat,row+1,n,ans,checkColumn,checkLeftDiagonal,checkRightDiagonal);
                
                //backtracking
                mat[row][col] = '.';
                checkColumn[col] = 0;
                checkLeftDiagonal[(n-1)+(col-row)]=0;
                checkRightDiagonal[col+row] = 0;
            }
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        
        List<List<String>> ans = new ArrayList<>();
        
        char mat[][]  = new char[n][n];
        for(int i =0;i<mat.length;i++){
            for(int j = 0;j<mat.length;j++){
                mat[i][j] = '.';
            }
        }
        
        int[] checkColumn = new int[n];
        int[] checkLeftDiagonal = new int[2*n-1];
        int[] checkRightDiagonal = new int[2*n+1];
      
        int curRow = 0;
        solveHelper(mat, curRow, n, ans, checkColumn, checkLeftDiagonal, checkRightDiagonal); //2nd argument is starting row

        return ans;
        
    }
}


  INTUTION
  
  FOR SAME COL - "checkColumn" Logic
 
  1 0 1 0 0  -> THIS ARRAY WILL TELL YOU THAT THE COLUMN ALREADY HAS A "QUEEN" OR NOT
  
  Q 0 0 0 0
  0 0 Q 0 0
  0 0 0 0 0
  0 0 0 0 0
  0 0 0 0 0


  FOR "LEFT BOTTOM TO TOP RIGHT" DIAGONAL
  
   0 1 2 3 4
0  0 1 2 3 4
1  1 2 3 4 5          CHECK THAT "Every diagonal has same number when we add (ROW + COL)"
2  2 3 4 5 6          that's why 'WE Use an array of length "2*n -1" (to keep record from 0 to 8 in this case)
3  3 4 5 6 7          [ 0 0 0 1 0 0 0 0 0 ] this means there's a QUEEN' is present in the diagonal whose ( Row+Col ) == 3;
4  4 5 6 7 8
  
  
  FOR "LEFT TOP TO BOTTOM RIGHT" DIAGONAL
  
   0 1 2 3 4
0  4 5 6 7 8
1  3 4 5 6 7          CHECK THAT "Every "\" diagonal has same number" when we DO => "(N-1) (COL - ROW)"
2  2 3 4 5 6          that's why 'WE Use an array of length "2*n -1" (to keep record from 0 to 8 in this case)
3  1 2 3 4 5         [ 0 0 0 1 0 0 0 0 0 ] this means there's a QUEEN' is present in the diagonal whose "(N-1) + ( COL - ROW ) == 3;
4  0 1 2 3 4
