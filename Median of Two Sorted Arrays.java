class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] arr = new int[m+n];
        for(int i=0; i<m; i++){
            arr[i] = nums1[i];
        }
        for(int i=0; i<n; i++){
            arr[i+m] = nums2[i];
        }
        Arrays.sort(arr);
        if(arr.length % 2 == 0)
            return (float)(arr[(m+n)/2] + arr[(m+n)/2 -1])/2;
        else
            return (arr[(m+n)/2 ] );
    }
}
