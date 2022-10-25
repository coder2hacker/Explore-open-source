class Solution {
    public int minimumTotal(List<List<Integer>> T) {
        for (int i = T.size() - 2; i >= 0; i--) 
            for (int j = T.get(i).size() - 1; j >= 0; j--) {
                int min = Math.min(T.get(i+1).get(j), T.get(i+1).get(j+1));
                T.get(i).set(j, T.get(i).get(j) + min);
            }
        return T.get(0).get(0);
    }
}
