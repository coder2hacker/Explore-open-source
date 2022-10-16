#https://leetcode.com/problems/generate-parentheses/
#22. Generate Parentheses



class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        
        
        def fun(open , close , output , arr):
            if (open ==0 and close ==0):
                arr.append(output)
                
                return 
            if (open!=0):
                op1= output
                op1+="("
                fun(open-1,close,op1,arr)
            if (close>open):
                op2=output
                op2+=")"
                fun(open,close-1,op2,arr)
        
        open = n
        close = n
        output=""
        arr=[]
        fun(open , close , output , arr)
        return arr
