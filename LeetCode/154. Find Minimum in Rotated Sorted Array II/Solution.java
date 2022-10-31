class Solution {
    public int findMin(int[] nums) {
        if(nums[0] < nums[nums.length - 1]){
            return nums[0];
        }
        
        if(nums.length == 1)
            return nums[0];
        
        if(nums[nums.length - 1] < nums[nums.length-2])
            return nums[nums.length - 1];
        for(int i = 0; i < nums.length-1; i++){
            if(nums[i] > nums[i+1])
                return nums[i+1];
        }
    
        return nums[0];
    }
}
