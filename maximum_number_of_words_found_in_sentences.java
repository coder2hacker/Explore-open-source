class Solution {
    public int mostWordsFound(String[] sentences) {
        int max=0;
        String []s = new String[sentences.length];
          for(int i=0;i<sentences.length;i++)
                s[i] = sentences[i];
        
          for(int i=0;i<sentences.length;i++){
           String []p  = s[i].split(" ");
            if(max<p.length){
                max = p.length;
            }
        }
        return max;
    }
}
Footer
