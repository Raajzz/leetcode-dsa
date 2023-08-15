class Solution {
public:
    int tabulation(vector<vector<int>> &obstacleGrid){
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
        dp[1][1] = 1;
        if(obstacleGrid[0][0] == 1){
            dp[1][1] = 0;
        }
        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[0].size(); j++){
                if(i != 1 || j != 1){                    
                    if(obstacleGrid[i-1][j-1] == 1){
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return tabulation(obstacleGrid);   
    }
};