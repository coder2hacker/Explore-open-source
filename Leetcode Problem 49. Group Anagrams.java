class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
         return sol2(strs);
    }
       public static List<List<String>> sol2(String[] str){
        Map<String,List<String>> map = new HashMap<>();
        for (String st : str) {
            char[] stArr = st.toCharArray();
            int freq[] = new int[26];
            for (int i = 0; i < stArr.length; i++) {
                int index = stArr[i]-'a';
                freq[index]++;
            }

            //use Arrays.toString
            // String stFreq = Arrays.toString(freq);

            //without using Arrays.toString
            StringBuilder sb= new StringBuilder() ;
            for (int i = 0; i < 26; i++) {
                sb.append(freq[i]);
                sb.append('|');   
            }
            String stFreq = sb.toString();

            List<String> valueList = map.getOrDefault(stFreq, new LinkedList<>());
            valueList.add(st);
            map.put(stFreq, valueList);
        }
        List<List<String>> ans = new LinkedList<>();
        ans.addAll(map.values());
        return ans;
    }
}
