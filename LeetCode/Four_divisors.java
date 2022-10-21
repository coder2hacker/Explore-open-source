class Solution {
    public int sumFourDivisors(int[] nums) {
       int res = 0;
       
       for (int i = 0; i < nums.length; i++){
           
           int sum = 0; int count = 0; 
           
           for (int j = 1; j <= Math.sqrt(nums[i]); j++){
               
               if (count <= 4)
               {
                   if(nums[i] % j == 0)
                   {
                       count++;
                       sum = sum + j;
                       
                        if ( (nums[i]/j) != j )
                        {
                            count++;
                            sum = sum + (nums[i]/j);
                        }
                   } 
                     
               }
               
           }
           
           if (count == 4)
               res = res + sum;
       }
       
       return res;
    }
}
