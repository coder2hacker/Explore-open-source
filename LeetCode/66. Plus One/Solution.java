// https://leetcode.com/problems/plus-one/

class Solution {
    public int[] plusOne(int[] digits) { 
        int length = digits.length;
        List<Integer> list = new ArrayList<>();
        int carry = 1;
        for(int i=length-1;i>=0;i--){            
            int sum = digits[i]+carry;
            carry = sum > 9 ? 1 : 0;                                            
            digits[i] = sum % 10;            
        }
        if(carry!=1){
            return digits;
        }
        int[] newArray = new int[length+1];
        newArray[0]=carry;
        System.arraycopy(digits, 0, newArray, 1, length);        
        return newArray;
    }
}
