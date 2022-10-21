// https://leetcode.com/problems/edit-distance/

class Solution {
    
    public int minDistance(String word1, String word2) {
        //let's apply bottom up dp like knapsack will do here
        int m = word1.length();
        int n = word2.length();
        int[][]dp = new int[m+1][n+1];
        for(int i =0;i<m;i++)
          Arrays.fill(dp[i],Integer.MAX_VALUE);
        //let's initialize the array
        for(int j=0;j<=n;j++)
            dp[0][j]= j;
        for(int i = 0;i<=m;i++)
            dp[i][0] =i;
        //now let's go for the answer hunt by building the entire array
        for(int i =1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(word1.charAt(i-1)==word2.charAt(j-1))
                    dp[i][j] =dp[i-1][j-1];
                else
                {
                    int min =Math.min(dp[i][j-1],dp[i-1][j]);
                    dp[i][j] = 1+Math.min(dp[i-1][j-1],min);
                }
            }
       // System.out.println(Arrays.deepToString(dp));
        return dp[m][n];
        }
}
