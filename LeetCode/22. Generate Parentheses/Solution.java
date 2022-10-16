// https://leetcode.com/problems/generate-parentheses/

class Solution {
    public List<String> generateParenthesis(int n) {
         List<String> result = new LinkedList<String>();
        process("", n, n, result);
        return result;
    }
    
    public void process(String prefix, int left, int right, List<String> result) {
        if (left == 0 && right == 0) {
            result.add(prefix);
            return;
        }
        if (left > 0) {
            process(prefix + '(', left - 1, right, result);
        }
        if (left < right) {
            process(prefix + ')', left, right - 1, result);
        }
    }
}
