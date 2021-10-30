class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n==1)
            return nums[0];
        if(nums[0]<nums[1] && nums[0]<nums[n-1])
            return nums[0];
        if(nums[n-1]<nums[n-2] && nums[n-1]<nums[0])
            return nums[n-1];
        int low = 0,high = n-1;
        while(low<high)
        {
            int mid = (low+high+1)/2;
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1])
                return nums[mid];
            if(nums[mid]>nums[0])
                low = mid+1;
            if(nums[mid]<nums[0])
                high = mid-1;
                
        }
        return nums[low];
            
    }
}
class FindMinimumInRotatedSortedArray
{
    public static void main(String[] args) {
        int[] nums = {3,4,5,1,2};
        Solution s = new Solution();
        System.out.println(s.findMin(nums));
    }
}