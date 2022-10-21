// https://leetcode.com/problems/combinations/

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(result, temp, n, k, 1);
        return result; 
    }

    private void helper(List<List<Integer>> result, List<Integer> temp, int n, int k, int i) {
        if (temp.size() == k) {
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int j = i; j <= n; j++) {
            temp.add(j);
            helper(result, temp, n, k, j + 1);
            temp.remove(temp.size() - 1);
        }
    }
}
