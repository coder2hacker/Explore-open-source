class Solution {
    public int maxProfit(int[] prices) {
        int minPrice1 = Integer. MAX_VALUE, minPrice2 = Integer. MAX_VALUE;
        int profit1 = 0, profit2 = 0;

        for (int currPrice : prices) {

            minPrice1 = Math.min(currPrice, minPrice1);
            profit1 = Math.max(profit1, currPrice - minPrice1);

            minPrice2 = Math.min(minPrice2, currPrice - profit1);
            profit2 = Math.max(profit2, currPrice - minPrice2);

        }

        return profit2;
    }
}
