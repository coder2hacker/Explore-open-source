class Solution {
    public String mergeAlternately(String word1, String word2) {
        String s = "";
        int m = word2.length();
        int n= word1.length();
        int l = m>n?n:m;
        int i=0;
        for(;i<l;i++){
           char ch = word1.charAt(i);
            s=s+ch;
            m--;
           char ch2 = word2.charAt(i);
            s=s+ch2;
            n--;
        }
        if(m>0){
            s=s+word2.substring(i);
        }else{
                  s=s+word1.substring(i);
        }
        return s;
    }
    
    
}
Footer
