class Solution {
    public int search(int[] nums, int target) {
        return search(nums, target, 0, nums.length-1);
    }
    static int search(int[] arr, int target, int start, int end){
        if (start > end){
            return -1;
        }
        int mid = start + (end - start)/2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[start] <= arr[mid]){
            if (target >= arr[start] && target <= arr[mid]){
                return search(arr, target, start, mid - 1);
            }
            else {
                return search(arr, target, mid + 1, end);
            }
        }
        if (target >= arr[mid] && target <= arr[end]){
            return search(arr, target,mid + 1, end);
        }
        return search(arr, target, start,mid - 1);
    }
}
