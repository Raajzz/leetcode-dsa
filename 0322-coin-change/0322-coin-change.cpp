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
    
    int tabulation(vector<int> &coins, int target){
        vector<vector<int>> dp(coins.size(), vector<int>(target + 1, 0));
        
        for(int i=0; i<=target; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }
        
        for(int index=1; index<coins.size(); index++){
            for(int currTarget = 0; currTarget <= target; currTarget++){                
                int notTake = 0 + dp[index-1][currTarget];
                int take = 1e9;
                if(coins[index] <= currTarget){
                    take = 1 + dp[index][currTarget - coins[index]];
                }
                dp[index][currTarget] = min(take, notTake);
            }
        }
        
        return dp[coins.size() - 1][target];
        
    }
    
    int coinChange(vector<int>& coins, int target) {
        int result = tabulation(coins, target);
        if(result >= 1e9){
            return -1;
        }
        return result;
    }
};