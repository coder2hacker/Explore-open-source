class Solution {
    public char repeatedCharacter(String s) {
        HashSet<Character> c =new HashSet<>();
        char ch='a';
        for(int i=0;i<s.length();i++){
            ch = s.charAt(i);
            if(c.isEmpty()!=true && c.contains(ch)){
                return ch;
            }else{
                c.add(ch);
            }
        }
        return ch;
    }
}
