class Solution {
    public int maximumGap(int[] nums) {
        int min = nums[0], max = nums[0], n = nums.length;
        for (int x : nums) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }
        if (min == max) return 0; // All elements are the same
        int bucketSize = (int) Math.ceil((double) (max - min) / (n - 1));
        int[] minBucket = new int[n];
        int[] maxBucket = new int[n];
        Arrays.fill(minBucket, Integer.MAX_VALUE);
        Arrays.fill(maxBucket, Integer.MIN_VALUE);
        for (int x : nums) {
            int idx = (x - min) / bucketSize;
            minBucket[idx] = Math.min(x, minBucket[idx]);
            maxBucket[idx] = Math.max(x, maxBucket[idx]);
        }
        int maxGap = bucketSize; // Maximum gap is always greater or equal to bucketSize
        int previous = maxBucket[0]; // We always have 0th bucket
        for (int i = 1; i < n; i++) {
            if (minBucket[i] == Integer.MAX_VALUE) continue; // Skip empty bucket
            maxGap = Math.max(maxGap, minBucket[i] - previous);
            previous = maxBucket[i];
        }
        return maxGap;
    }
}
