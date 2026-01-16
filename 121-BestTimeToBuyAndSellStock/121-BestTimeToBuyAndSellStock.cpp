// Last updated: 1/16/2026, 8:21:33 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Track the minimum price so far (best day to buy)
            minPrice = min(minPrice, price);

            // Check if selling today gives a better profit
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
