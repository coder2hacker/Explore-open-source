class Solution {
    public String decodeMessage(String key, String message) {
        
        HashMap<Character,Character> map = new HashMap<>();
        char c ='a';
        for(int i=0;i<key.length();i++){
            if(key.charAt(i)==' ')
            map.put(' ',' ');
            if(!map.containsKey(key.charAt(i))){
            map.put(key.charAt(i),c);
            c++;
            }
        }
        String s="";
     //   System.out.println(map);
        for(int i=0;i<message.length();i++){
            if(message.charAt(i)==' ')
                s=s+" ";
            else
            s=s+map.get(message.charAt(i));
        }
        return s;
    }
}
