class Solution {
public:
    int recursion(int index, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(index == 0){
            if(amount % coins[index] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notTake = recursion(index - 1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[index]){
            take = recursion(index, amount - coins[index], coins, dp);
        }
        return dp[index][amount] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return recursion(coins.size() - 1, amount, coins, dp);
    }
};