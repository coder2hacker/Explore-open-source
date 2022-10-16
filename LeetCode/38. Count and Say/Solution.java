// https://leetcode.com/problems/count-and-say/

class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
        String res = countAndSay(n-1);
        StringBuilder ans = new StringBuilder();
        int left = 0, right = 0;
        while(right < res.length()){
            int counter = 0;
            while(right<res.length() && res.charAt(left) == res.charAt(right)){
                counter++;
                right++;
            }
            ans.append(counter);
            ans.append(res.charAt(left));
            left = right;
        }
        return ans.toString();
    }
}
