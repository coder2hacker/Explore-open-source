// https://leetcode.com/problems/length-of-last-word/

class Solution {
    public int lengthOfLastWord(String s) {
        int i = 0;
        int flag = 1;
        s=s.trim();

        for (i= s.lastIndexOf(" ")+1; i<s.length()-1;i++) {
            flag++;
        }
        return flag;
    }
}
