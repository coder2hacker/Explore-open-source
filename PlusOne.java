class Solution {
    public int[] plusOne(int[] digits) {
       int size=digits.length-1;
       
        while(size>=0&&digits[size]==9){
            digits[size]=0;
            size--;
        }
        if(size>=0){
            digits[size]=digits[size]+1;
            return digits;
        }
        else{
            int a[]=new int[digits.length+1];
            for(int i=a.length-1;i>0;i--){
                a[i]=digits[i-1];
            }
            a[0]=1;
            return a;
        }
    }
}
