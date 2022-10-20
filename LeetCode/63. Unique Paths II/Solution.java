// https://leetcode.com/problems/unique-paths-ii/

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        boolean flag = false;
        for(int i=0;i<m;i++){
		   //if we found obstacle then make flag true which means now path cannot be considered
            if(obstacleGrid[i][0]==1)
                flag = true;
			// if we found 0 on path and we have not found any obstacle yet then we can mark that step as 1
            if(obstacleGrid[i][0]==0 && !flag)
                dp[i][0] = 1;
			// here condition is obstacle is found so path cannot be considered so marked as 0
            else
                dp[i][0] = 0;
        }
        flag = false;
        for(int j=0;j<n;j++){
		 //if we found obstacle then make flag true which means now path cannot be considered
            if(obstacleGrid[0][j]==1)
                flag = true;
			// if we found 0 on path and we have not found any obstacle yet then we can mark that step as 1
            if(obstacleGrid[0][j]==0 && !flag)
                dp[0][j] = 1;
            else
			    // here condition is obstacle is found so path cannot be considered so marked as 0
                dp[0][j] = 0;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
			    // if no obstacle then we can consider the step
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
}
