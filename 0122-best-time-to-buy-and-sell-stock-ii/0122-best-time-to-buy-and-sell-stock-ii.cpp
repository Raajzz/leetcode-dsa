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
    
    int tabulation(vector<int> &prices){
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        
        for(int index=prices.size() - 1; index>=0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy == 0){
                    profit = max(
                        -prices[index] + dp[index + 1][1], 
                        dp[index + 1][0]
                    );
                } else {
                    profit = max(
                        prices[index] + dp[index + 1][0],
                        dp[index + 1][1]
                    );
                }
                dp[index][buy] = profit;
            }
        }
        
        return dp[0][0];
    }
    
    int maxProfit(vector<int>& prices) {
        return tabulation(prices);
    }
};