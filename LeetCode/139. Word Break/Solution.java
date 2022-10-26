class Solution {
    // Regular DFS with 2^N in time complexity
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        return dfs(s, words, map);
    }
    
    private boolean dfs(String s, Set<String> words){
        int len = s.length();
        if(len == 0) return true;
        
        for(int i = 1; i <= len; i++){
            if(words.contains(s.substring(0, i)) && dfs(s.substring(i), words)){
                return true;   
            }
        }
        
        return false;
    }
}

Now just add a bit of code to make it N^2 time complexicty
class Solution {
    // use memoization: at what substring which could lead to a correct answer
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<>(wordDict);
        Map<String, Boolean> map = new HashMap<>(); // memoization
        return dfs(s, words, map);
    }
    
    private boolean dfs(String s, Set<String> words, Map<String, Boolean> map){
        if(map.containsKey(s)) return map.get(s);
        int len = s.length();
        if(len == 0) return true;
        
        for(int i = 1; i <= len; i++){
            if(words.contains(s.substring(0, i)) && dfs(s.substring(i), words, map)){
                map.put(s.substring(0, i), true);
                return true;   
            }
        }
        map.put(s, false);
        return false;
    }
}
