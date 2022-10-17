class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        int ans[] = new int[l1+l2];
        int i=0;
        int j=0;
        int k=0;
        while(i<l1 && j<l2){
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                k++;
                i++;
            }
            else{
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<l1){
            ans[k] = nums1[i];
            k++;
            i++;
        }
        while(j<l2){
            ans[k] = nums2[j];
            k++;
            j++;
        }
        for(int iter=0;iter<ans.length;iter++){
                    System.out.print(ans[iter]+" ");
        }
        int l = ans.length;
         System.out.print(l/2 +" "+(l/2+1));
        double answer=0.0;
        if(l%2==0){
            answer = (ans[l/2]+ans[l/2-1])/2.0;
        }
        else{
            answer = ans[l/2];
        }
        return answer;
    }
}
