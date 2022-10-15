# https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
      
        # Method - 1 ( Convert int to str and compare )
        temp = str(x)
        return temp == temp[::-1]
    
        # Method - 2 ( Reverse the number and compare )
        ori = x
        tempcopy = 0
        while(x > 0 ):
            tempcopy = tempcopy*10 + x % 10
            x = x//10
        return tempcopy == ori
      
        
