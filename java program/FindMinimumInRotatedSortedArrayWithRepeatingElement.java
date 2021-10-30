package java program;
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n==1)
            return nums[0];
        int low = 0,high = n-1;
        if (nums[low] < nums[high]) return nums[low];
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[high])
                low = mid + 1;
            else if(nums[mid]<nums[high])
                high = mid;
            else
                high--;
        }
        return nums[high];
    }
}
public class FindMinimumInRotatedSortedArrayWithRepeatingElement {
    public static void main(String[] args) {
        int[] nums = {2,2,2,0,1};
        Solution s = new Solution();
        System.out.println(s.findMin(nums));
    }
}
