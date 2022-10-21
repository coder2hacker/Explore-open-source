class Solution {
    public boolean isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        if(n%4!=0 && n !=1){
            return false;
        }
        
        if(n==1){
            return true;
        }
        else{
            return isPowerOfFour(n/4);
        }
    }
}
