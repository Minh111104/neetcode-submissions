class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buyPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            } else if (prices[i] - buyPrice > profit) {
                profit = prices[i] - buyPrice;
            }
        }
        return profit;
    }
};
