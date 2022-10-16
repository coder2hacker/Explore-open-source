// https://leetcode.com/problems/divide-two-integers/

class Solution {
     public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1)
             return Integer.MAX_VALUE; 

        boolean negative = dividend < 0 ^ divisor < 0; 
        
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
       
    int quotient = 0, subQuotient = 0;
        
        while (dividend - divisor >= 0) {
            for (subQuotient = 0; dividend - (divisor << subQuotient << 1) >= 0; subQuotient++);
            quotient += 1 << subQuotient; 
            dividend -= divisor << subQuotient; 
        }
        return negative ? -quotient : quotient;
    }
}
