// https://leetcode.com/problems/reverse-integer/

class Solution {
    public int reverse(int x) {
        int a = Math.abs(x);
        int num = 0;
        int limit = Integer.MAX_VALUE/10;
        while(a>0){
            if(num>limit)   return 0;
            int rem = a%10;
            num = num*10+rem;
            a = a/10;
        }
        if(x<0) return (num*-1);
        return num;
    }
}
