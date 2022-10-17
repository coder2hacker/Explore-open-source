class Solution {
    public int minimumRecolors(String blocks, int k) {
       
        int minconv=blocks.length();
        for(int j=0;j<blocks.length();j++){
             int c=0;
        int conv=0;
        for(int i=j;i<blocks.length();i++){
            char ch = blocks.charAt(i);
            if(ch=='W')
            {
                conv++;
                //  System.out.println("conv="+conv);
            }
                c++;
        //     System.out.println("count="+c);
            if(c==k){
                if(conv<minconv)
                    minconv=conv;
             //  System.out.println(minconv);
                break;
            }
        }
        }
        return minconv;
    }
}
