# leetcode 202. Happy Number
#https://leetcode.com/problems/happy-number/


#this is problem based on linked list fast and slow pointer and cycle detection method
#using to pointer fast and slow 

class Solution:
    def isHappy(self, n: int) -> bool:
        def func(n):
            n1=n
            s=0
            while(n1!=0):
                v=(n1%10)
                n1=n1//10
                s=s+v**2
            return s
        
        slow=n
        fast=n
        slow=func(slow)
        fast=func(func(fast))
        while(slow!=fast):
            slow=func(slow)
            fast=func(func(fast))
        
        if (slow==1):
            return True
        return False
      
      

#solution without using linkedlist concept 
class Solution:
    def isHappy(self, n: int) -> bool:
        mem = set()
        while n != 1:
            n = sum([int(i) ** 2 for i in str(n)])
            if n in mem:
                return False
            else:
                mem.add(n)
        else:
            return True    
