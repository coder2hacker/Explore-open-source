class Main
{
    // Function to find the longest bitonic subsequence in an array
    public static int calculateLBS(int[] nums)
    {
        int n = nums.length;
 
        // base case
        if (n == 0) {
            return 0;
        }
 
        // `I[i]` store the length of the longest increasing subsequence,
        // ending at `nums[i]`
        int[] I = new int[n];
 
        // `D[i]` stores the length of the longest decreasing subsequence,
        // starting with `nums[i]`
        int[] D = new int[n];
 
        I[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && I[j] > I[i]) {
                    I[i] = I[j];
                }
            }
            I[i]++;
        }
 
        D[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[j] < nums[i] && D[j] > D[i]) {
                    D[i] = D[j];
                }
            }
            D[i]++;
        }
 
        // consider each element as a peak and calculate LBS
        int lbs = 1;
        for (int i = 0; i < n; i++) {
            lbs = Integer.max(lbs, I[i] + D[i] - 1);
        }
 
        return lbs;
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
 
        System.out.print("The length of the longest bitonic subsequence is " +
                calculateLBS(nums));
    }
}
