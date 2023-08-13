class Solution {
public:
    int recursion(vector<int> &coins, int target, int index, vector<vector<int>> &dp){
        if(index == 0){
            if(target % coins[0] == 0){
                return target / coins[0];
            }
            return 1e9;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        int notTake = 0 + recursion(coins, target, index - 1, dp);
        int take = 1e9;
        if(coins[index] <= target){
            take = 1 + recursion(coins, target - coins[index], index, dp);
        }
        return dp[index][target] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int target) {
        vector<vector<int>> dp(coins.size(), vector<int>(target+1, -1));
        int result = recursion(coins, target, coins.size() - 1, dp);
        if(result >= 1e9){
            return -1;
        }
        return result;
    }
};