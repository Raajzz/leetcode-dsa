class Solution {
public:
    int recursion(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy == 0){
            profit = max(
                -prices[index] + recursion(prices, index + 1, 1, dp), 
                recursion(prices, index + 1, 0, dp)
            );
        } else {
            profit = max(
                prices[index] + recursion(prices, index + 1, 0, dp),
                recursion(prices, index + 1, 1, dp)
            );
        }
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recursion(prices, 0, 0, dp);
    }
};