class Solution {
    public int lengthOfLIS(int[] nums) {
        // DP
        // return dp(nums);
        
        // Patience sort 
        return patienceSort(nums);
    }
    
    private int patienceSort(int[] nums) {
        // we need the top of every number in the piles
        // Piles will be created such that we scan the
        // piles array for the leftmost point where we
        // can place a number in nums array such that
        // the number in leftmost piles will be greater
        // than the number of nums array
        int[] piles = new int[nums.length];
        int numPiles = 0;
        for (int i: nums) {
            int l = 0, r = numPiles;
            // this variation of binary search finds
            // the first index where piles[index] < i
            // hence when we find that index, we move
            // l to mid + 1, since the piles array
            // will always be sorted, we will always have
            // find our placement index at l becuause when
            // piles[mid] > i we reduce search space by half
            // and at this point r will be at mid
            while (l < r) {
                int mid = l + (r - l)/2;
                if (piles[mid] < i)
                    l = mid + 1;
                else
                    r = mid;
            }
            piles[l] = i;
            if (l == numPiles)
                numPiles++;
        }
        
        return numPiles;
        
    }
    
    private int dp(int[] nums) {
        // dp[i] represents longest increasing
        // subsequence for nums[i]
        int[] dp = new int[nums.length];
        
        // for every nums[i] initially that nums[i]
        // is a part of the LIS
        Arrays.fill(dp, 1);
        int max = 1;
        
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                // we found a number at j which is greater than
                // i hence we can have a subsequence for number
                // at j which will include number at i
                if (nums[j] > nums[i]) {
                    // since nums[i] < nums[j] we can either extend
                    // LIS of i by including j if dp[j] < dp[i] + 1
                    // or we move forward because we already have a
                    // IS >= IS at I + 1
                    dp[j] = Math.max(dp[i] + 1, dp[j]);
                    // check if we have a length greater than max
                    // at dp[j] which possibly got updated
                    max = Math.max(max, dp[j]);
                }
            }
        }
        
        return max;
    }
}
