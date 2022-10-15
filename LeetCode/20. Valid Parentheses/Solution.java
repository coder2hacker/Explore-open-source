//  https://leetcode.com/problems/valid-parentheses

class Solution {
    public boolean isValid(String s) {
         Stack<Character> st=new Stack<Character>();
          for(char a:s.toCharArray())
        {
           
			//Check if stack not empty and the top element corresponds to curr char
            if(!st.isEmpty() && (st.peek()==a-1 || st.peek()==a-2))
                st.pop();
			//else these migh be starting brackets or unsatisfied closing brackets
            else
                st.push(a);
        }
           
           return st.isEmpty();
    }
}
