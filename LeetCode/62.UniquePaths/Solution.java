// https://leetcode.com/problems/unique-paths/description/ //



class Solution {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        if(n == 1 || m == 1) return 1;
        for(int i = 0; i < dp.length; i++) dp[i] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
}