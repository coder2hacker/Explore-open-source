class Solution {
    public int[] shuffle(int[] nums, int n) {
         int num2[] = new int[nums.length];
        for(int i = 0,j=0;j<num2.length;i++,j++){
            num2[j] = nums[i];
            j++;
            num2[j] = nums[n+i];
        }
        return num2;
    }
}
