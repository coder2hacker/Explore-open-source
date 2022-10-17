class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        int cache[][] = new int[m+1][n+1];
        for(int[] rows:cache){
            Arrays.fill(rows, -1);
        }
        return sol(s,p,m,n,cache)==1?true:false;
    }
    private static int sol(String s,String p,int m,int n,int[][] cache) {
        if(m==0){
            if(n==0){
                return 1;
            }
            if(p.charAt(n-1)=='*'){
                return cache[m][n] =sol(s, p, m, n-1,cache);
            }
            else{
                return 0;
            }
        }
        if(n==0){
            return 0;
        }
        if(cache[m][n]!=-1){
            return cache[m][n];
        }
        if(s.charAt(m-1)==p.charAt(n-1) || p.charAt(n-1)=='?'){
            return cache[m][n] = sol(s, p, m-1, n-1,cache);
        }
        else if(p.charAt(n-1)=='*'){
            int case1 = sol(s, p, m-1, n,cache); //match
            int case2 = sol(s, p, m, n-1,cache); //dont match
            return cache[m][n] = Math.max(case1,case2);
        }
        else{
            return 0;
        }
    }
}
