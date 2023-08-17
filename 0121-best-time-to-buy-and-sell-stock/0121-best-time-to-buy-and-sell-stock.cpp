class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = prices[prices.size() - 1];
        int profit = 0;
        for(int i=prices.size()-2; i>=0; i--){
            maxPrice = max(prices[i], maxPrice);
            profit = max(maxPrice - prices[i], profit);
        }
        return profit;
    }
};