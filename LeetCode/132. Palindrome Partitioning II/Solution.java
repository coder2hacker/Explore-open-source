class Solution {
    Boolean isPalindrome(int i,int j,String str){
        while(i<j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    public int minCut(String s) {
        int N = s.length();
        int[]dp =new int[N];
        for(int i=0;i<N;i++){
            dp[i] = -1;
        }
        return minimumPartition(0,N,s,dp) -1 ;//-1 is done because for ABC code will give 3 partitions as 3 Palindromic substring A,B,C be formed. A|B|C
    }
    
    int minimumPartition(int i,int N, String str,int[]dp){
        if(i == N){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = (int)1e8;
        for(int j=i;j<N;j++){
            if(isPalindrome(i,j,str)){//If it is Palindrome,we can do partition
                int partitions = 1 + minimumPartition(j+1,N,str,dp);
                mini = Math.min(mini,partitions);
            }
        }//for ends
        dp[i] = mini;
        return dp[i];
    }
}
