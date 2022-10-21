// https://leetcode.com/problems/sort-colors/

class Solution {
    public void swap(int x, int y, int[] nums){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    public void sortColors(int[] nums) {
        int front=0;
        int middle=0;
        int rear=nums.length - 1;
        while(middle <= rear){
            if(nums[middle] == 0){
                swap(front,middle,nums);
                front++;
                middle++;
            }
            else if(nums[middle] == 1) middle++;
            
            else{
                swap(middle,rear,nums);
                rear--;
            }
        }
    }
}
