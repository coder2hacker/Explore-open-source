// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 1;
        int k = 1;
        for (int i = 0; i < nums.length - 1; i++) {
            int first = nums[i];
            int second = nums[i + 1];
            if (first != second) {
                nums[index] = second; 
                index++;
                k++;
            }
        }
        return k;
    }
}
