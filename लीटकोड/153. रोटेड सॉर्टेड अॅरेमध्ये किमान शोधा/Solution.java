class Solution {
    public int findMin(int[] nums) {
        if(nums.length == 1)
            return nums[0];
        else if(nums[0] < nums[nums.length - 1])
            return nums[0];
        else if(nums.length > 1 && nums[nums.length-2] > nums[nums.length - 1])
            return nums[nums.length - 1];
        
        int low = 0;
        int high = nums.length - 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(low == high)
                return nums[low];
            else if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            else if(nums[mid] < nums[mid-1])
                return nums[mid];
            else if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
                return nums[low];
            else if(nums[low] < nums[mid])
                low = mid+1;
            else if(nums[mid] < nums[high])
                high = mid-1;
        }
        
        return -1;
    }
}
