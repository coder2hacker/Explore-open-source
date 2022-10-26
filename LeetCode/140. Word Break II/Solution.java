class Solution {
    List<String> ans;
    public void breakWord(String s, int start, Set<String> dict, List<String> curr){
        for(int i=start+1;i<=s.length();i++){
            String f = s.substring(start, i);
            if(dict.contains(f)){
                curr.add(f);
                if(i==s.length()){
                    String[] stringparts = curr.toArray(String[]::new);
                    ans.add(String.join(" ", stringparts));
                }    
                else breakWord(s, i, dict, curr);
                curr.remove(curr.size()-1);
            }
        }
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        ans = new ArrayList<String>();
        Set<String> dict = new HashSet();
        for(String w:wordDict) dict.add(w);
        breakWord(s, 0, dict, new ArrayList<String>());
        return ans;
    }
}
