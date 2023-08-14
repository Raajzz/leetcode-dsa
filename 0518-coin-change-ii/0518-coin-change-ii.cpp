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
    
    int tabulation(int amount, vector<int> &coins){
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }
        
        for(int index=1; index<coins.size(); index++){
            for(int currAmount = 0; currAmount <= amount; currAmount++){
                int notTake = dp[index - 1][currAmount];
                int take = 0;
                if(currAmount >= coins[index]){
                    take = dp[index][currAmount - coins[index]];
                }
                dp[index][currAmount] = notTake + take;
            }
        }
        
        return dp[coins.size() - 1][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        return tabulation(amount, coins);
    }
};