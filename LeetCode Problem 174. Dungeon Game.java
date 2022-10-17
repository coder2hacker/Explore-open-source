class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length;
        int cache[][] = new int[m+1][n+1];
        for(int[] rows:cache){
            Arrays.fill(rows, 0);
        }
        return sol(dungeon,0,0,m-1,n-1,cache);
        
    }
    int sol(int[][] d,int cr,int cc,int dr,int dc,int[][] cache){
        if(cr>dr||cc>dc){
            return Integer.MAX_VALUE;
        }
        if(cc==dc&&cr==dr){
            return d[cr][cc]>0?1:(Math.abs(d[cr][cc])+1);
        }
        if(cache[cr][cc]!=0){
            return cache[cr][cc];
        }
        int c1 = sol(d,cr+1,cc,dr,dc,cache);
        int c2 = sol(d,cr,cc+1,dr,dc,cache);
        
        int iniHealth = Math.min(c1,c2)-d[cr][cc];
        return cache[cr][cc] = iniHealth > 0 ? iniHealth : 1;
    }
}
