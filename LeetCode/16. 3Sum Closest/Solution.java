// https://leetcode.com/problems/3sum-closest/

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n=nums.length;
        int minDiff=Integer.MAX_VALUE;
        int ans=0;
        for(int i=0;i<n-2;i++){
            int low=i+1,high=n-1;
            while(low<high){
                int temp=nums[i]+nums[low]+nums[high];
                if(Math.abs(target-temp)<minDiff){
                    ans=temp;
                    minDiff=Math.abs(target-temp);
                }
                if(temp==target){
                    return target;
                }
                else if(temp>target){
                        high--;
                }
                else{
                    low++;
                }
            }
        }
        return ans;
            
    }       
}
