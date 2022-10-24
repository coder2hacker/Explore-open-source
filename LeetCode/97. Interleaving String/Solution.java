class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {

        if(s1.length() + s2.length() != s3.length()){
            return false;
        }

        int[][][] dp = new int[s1.length()+1][s2.length()+1][s3.length()+1];

        for(int arr[][] : dp){
            for(int t[]: arr){
                Arrays.fill(t, -1);
            }
        }

        return getAns(s1,s2,s3, 0, 0, 0, dp);
    }

    public boolean getAns(String s1, String s2, String s3, int is1, int is2, int is3, int[][][] dp){

        if(dp[is1][is2][is3] != -1){
            if(dp[is1][is2][is3] == 0){
                return false;
            }
            return true;
        }

        if(is1 == s1.length() && is2 == s2.length() && is3 == s3.length()){
            dp[is1][is2][is3] = 1;
            return true;
        }

        if(is3 == s3.length()){
            dp[is1][is2][is3] = 0;
            return false;
        }

        // test case : s1 = "" s2 = "ab" s3 = "ab"
        if(is1 == s1.length()){

            int j = is3;

            for(int i = is2; i < s2.length(); i++){


                if(s2.charAt(i) != s3.charAt(j)){
                    return false;
                }
                j++;
            }


            boolean ans = j == s3.length();

            if(ans){
                dp[is1][is2][is3] = 1;
            }else {
                dp[is1][is2][is3] = 0;
            }

            return ans;
        }

        // test case : s1 = "ab" s2 = "" s3 = "ab"
        if(is2 == s2.length()){

            int j = is3;

            for(int i = is1; i < s1.length(); i++){

                if(s1.charAt(i) != s3.charAt(j)){
                    return false;
                }
                j++;
            }


            boolean ans = j == s3.length();

            if(ans){
                dp[is1][is2][is3] = 1;
            }else {
                dp[is1][is2][is3] = 0;
            }

            return ans;
        }



        // test case : s1 = "aab" s2 = "abc" s3 : "aaabbc"
        boolean s1match = s1.charAt(is1) == s3.charAt(is3);
        boolean s2match = s2.charAt(is2) == s3.charAt(is3);

        
        if(s1match && s2match){
            boolean ans = getAns(s1, s2, s3, is1 + 1, is2, is3 + 1, dp) ||
                    getAns(s1, s2, s3, is1, is2 + 1, is3 + 1, dp);

            if(ans){
                dp[is1][is2][is3] = 1;
            }else {
                dp[is1][is2][is3] = 0;
            }

            return ans;
        }


        else if(s1match){
            boolean ans = getAns(s1, s2, s3, is1 + 1, is2, is3 + 1, dp);

            if(ans){
                dp[is1][is2][is3] = 1;
            }else {
                dp[is1][is2][is3] = 0;
            }

            return ans;
        }

        else if(s2match){
            boolean ans = getAns(s1, s2, s3, is1, is2 + 1, is3 + 1, dp);

            if(ans){
                dp[is1][is2][is3] = 1;
            }else {
                dp[is1][is2][is3] = 0;
            }

            return ans;
        }

        dp[is1][is2][is3] = 0;
        return false;

    }
}
