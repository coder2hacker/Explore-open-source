class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < m; i++) {
            if (map.containsKey(nums1[i])) {
                map.put(nums1[i], map.get(nums1[i]) + 1);
            } else {
                map.put(nums1[i], 1);
            }
        }
        for (int i = m; i < nums1.length; i++) {
            int idx = i - m;
            if (map.containsKey(nums2[idx])) {
                map.put(nums2[idx], map.get(nums2[idx]) + 1);
            } else {
                map.put(nums2[idx], 1);
            }
        }
        int count = 0;
        for (Integer num : map.keySet()) {
            for (int i = 0; i < map.get(num); i++) {
                nums1[count++] = num;
            }
        }
    }
}
