// https://leetcode.com/problems/jump-game/

class Solution {
    public boolean canJump(int[] nums) {
        int Max_jump = nums[0];
        int n = nums.length;
        if (Max_jump == 0 && n > 1) {
            return false;
        }
        int i = 1;
        while(i < n) {
            Max_jump--;
            if (Max_jump < nums[i]) {
                Max_jump = nums[i];
            }
            if (Max_jump <= 0 && i != n-1) {
                return false;
            }
            i++;
        }
        return true;
    }
}
