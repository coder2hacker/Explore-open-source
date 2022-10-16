// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack();
        stack.push(-1);
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s.charAt(i) == '(')
                stack.push(i);
            else if(s.charAt(i) == ')')
            {    
                stack.pop();
                if(stack.empty())
                    stack.push(i);
                else
                    maxLen = Math.max(maxLen, i - stack.peek());     
            }
        }
        return maxLen;
    }
}
