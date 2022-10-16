// https://leetcode.com/problems/next-permutation/

class Solution {
    public void nextPermutation(int[] nums) {
        /*
        Approach:
        1. We loop from the end to the point where the value of the element is just smaller than the previous digit.
        2. Then We loop from the end to that point and find the element which is just greater than the element.
        3. We swap the two elements.
        4. Finally we reverse the sequence from end to the index of the point + 1;
        */
        
        int lastIndex = nums.length - 2; // For Comparing The Element With the Next Element
        int swapIndex = nums.length - 1; // For Swapping Value With The Element Just Greater.
        
        // Finding The Index Of The First Smaller Element Than Previous
        while(lastIndex >= 0 && nums[lastIndex] >= nums[lastIndex + 1]){
            lastIndex--;
        }
        
        // Swapping The Number With The Previous Just Greater Value
        if(lastIndex >= 0){
            
            while(nums[swapIndex] <= nums[lastIndex]){
                swapIndex--;
            }
            
            swap(nums, lastIndex, swapIndex);
            
        }
        
        // Reversing All Elements Behind The Number
        // In The Edge Case Of The Number Being In Descending Order, The Whole Number Will Be Reversed
        reverse(nums, lastIndex+1);
        
    }
    
    //Swap Function
    public void swap(int[] nums, int i, int j){
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        
    }
    
    // Reverse Function
    public void reverse(int[] nums, int i){
        
        int j = nums.length - 1;
        
        while(i<j){
            swap(nums, i, j);
            i++;
            j--;
        }
        
    }
    
}
