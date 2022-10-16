// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
    public int search(int[] nums, int target) {
        int n= nums.length;
        int start= 0;
        int end= n-1;
        int mid= (start+end)/2;
        
        //  Base Cases:
        
        //  1. If length of array is 1
        if(n == 1){
            if(nums[0] == target){
                return 0;
            }
            return -1;
        }
        
         // 2. If length of array is 2
        if(n == 2){
            if(nums[0] == target){
                return 0;
            }
            else if(nums[1] == target){
                return 1;
            }
            return -1;
        }
        
        //  3. If the array is not rotated
        if(nums[n-1] > nums[0]){
            return binarySearch(nums, 0, n-1, target);
        }
        
        boolean status= false;
        int rotateIndex= -1;
        
        //  Finding the index where rotation has taken place
        while(start<= end){
            mid= (start+end)/2;
			
            if(nums[mid-1] > nums[mid]){
                if(mid+1 >= n){
                    rotateIndex= mid;
                    break;
                }
                
                if( mid+1 < n && nums[mid] < nums[mid+1]){
                    rotateIndex= mid;
                    break;
                }
            }
            
            //  Base Case (If start+1 == end)
            //  In this case mid value won't update
            if(start+1 == end){
                start= end;
                mid= (start+end)/2;
            }
            
            if(nums[start] > nums[mid]){
                //  Discarding the right subarray
                end= mid;
            }
            else{
                //  Discarding the left subarray
                start= mid;
            }
        }
        
        if(target > nums[n-1]){
            return binarySearch(nums, 0, rotateIndex, target);
        }
        else{
            return binarySearch(nums, rotateIndex, n-1, target);
        }
    }
    
    public int binarySearch(int[] nums, int start, int end, int target){
        int mid= (start+end)/2;
        
        while(start<= end){
            mid= (start+end)/2;

            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] > target){
                end= mid-1;
            }
            else{
                start= mid+1;
            }
        }
        return -1;
    }
}
