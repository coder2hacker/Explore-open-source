class Solution {
	public int numDistinct(String s, String t) {
		return dfs(0,0,t,s,new Integer[t.length()][s.length()]);
	}

	public int dfs(int tIndex,int sIndex,String t,String s,Integer[][] memo){
		if(tIndex==t.length()) return 1;     
		if(sIndex==s.length()) return 0;
		if(memo[tIndex][sIndex]!=null) return memo[tIndex][sIndex];
		int count = 0;
		if(s.charAt(sIndex)==t.charAt(tIndex)) 
			count += dfs(tIndex+1,sIndex+1,t,s,memo);
		count+= dfs(tIndex,sIndex+1,t,s,memo);
		return memo[tIndex][sIndex] = count;
	} 
}
