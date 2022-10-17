// https://leetcode.com/problems/two-sum/ 

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hm = new HashMap<>();
        for(int i = 0; i < nums.length;i++) {
            if(hm.containsKey(target - nums[i])) {
                return new int[] {hm.get(target - nums[i]), i};
            } else {
                hm.put(nums[i], i);
            }
        }
        return null;
    }
}
//Two pointer method
//If the array is sorted and you want to check if there exists two numbers adding to a given sum or not.
class Solution {
    public boolean twoSum(int[] nums, int target) {
        int i=0;
        int j=nums.length-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target){
                return true;
            }else if(sum<target){
                //if the sum is lesser then we increase the i pointer cuz we need a larger value to make the sum.(array is sorted)
                i++;
            }else{
                //if the sum is greater then we decrease the j pointer cuz we need a smaller value.
                j--;
            }
        }
        return false;
    }
}
Time complexity=O(n)
space complexity=O(1)
