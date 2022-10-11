class Solution {
    public String addBinary(String a, String b) {
       int a1=a.length();
        int b1=b.length();
        int carry=0;
        int i=0;
        String result ="";
        while(i<a1||i<b1||carry!=0){
            int x=0;
            if(i<a1&&a.charAt(a1-1-i)=='1')x=1;
            int y=0;
            if(i<b1&&b.charAt(b1-1-i)=='1')y=1;
            result=(x+y+carry)%2+result;
            carry=(x+y+carry)/2;
            i++;
        }
        return result;
    }
}
