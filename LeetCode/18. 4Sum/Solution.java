// https://leetcode.com/problems/4sum/

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 3; i++) {
            for(int j = i + 1; j < nums.length - 2; j++) {
                long res = (nums[i] + nums[j]);
                long remSum = target - res;
                int front = j + 1, back = nums.length - 1;
                while(front < back) {
                    long twoSum = nums[front] + nums[back];
                    if(twoSum < remSum) front++;
                    else if(twoSum > remSum) back--;
                    else {
                        List<Integer> sum = new ArrayList<>();
                        sum.add(nums[i]);
                        sum.add(nums[j]);
                        sum.add(nums[front]);
                        sum.add(nums[back]);
                        ans.add(sum);
                        
                        while(front < back && nums[front] == sum.get(2)) front++;
                        while(front < back && nums[back] == sum.get(3)) back--;
                    }
                }
                while(i < nums.length - 1 && nums[i + 1] == nums[i]) i++;
                while(j < nums.length - 1 && nums[j + 1] == nums[j]) j++;
            }
        }
        return ans;
    }
}
