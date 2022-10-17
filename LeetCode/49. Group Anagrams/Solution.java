// https://leetcode.com/problems/group-anagrams/

class Solution {
    public List<List<String>> groupAnagrams(String[] s) {
        if (s.length == 1) {
            List<String> list = new ArrayList<>(1);
            list.add(s[0]);
            List<List<String>> res = new ArrayList<>(1);
            res.add(list);
            return res;
        }
        Map<String, List<String>> map = new HashMap<>();
        for (String word : s) {
            char[] alphabet = new char[26];
            for (char c : word.toCharArray()) {
                alphabet[c - 'a']++;
            }
            String key = new String(alphabet);
            if (map.containsKey(key)) {
                map.get(key).add(word);
            } else {
                List<String> list = new ArrayList<>();
                list.add(word);
                map.put(key,list);
            }
        }
        return new ArrayList<>(map.values());
    }
}
