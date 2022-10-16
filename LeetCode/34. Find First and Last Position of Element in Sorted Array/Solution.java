// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int []arr = {-1, -1};
        int i;
        for(i=0; i<nums.length; i++){
            if(nums[i] == target){
                arr[0] = i;
                break;
            }
        }
        
        if(arr[0] == -1)
            return arr;
        
        
        while(i < nums.length && nums[i] == target)
            ++i;
        arr[1] = --i;
        
        return arr;
    }
}
