class Solution {
    public int climbStairs(int n) {
        
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        
        return sol(n, dp);
    }
    
    private int sol(int n, int[] dp) {
        
        if(n == 0 || n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int c1 = sol(n - 1, dp);
        int c2 = sol(n - 2, dp);
        
        return dp[n] = c1 + c2;
    }
}
