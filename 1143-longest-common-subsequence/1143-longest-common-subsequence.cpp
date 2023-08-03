class Solution {
public:

    int recursion(int index1, int index2, string text1, string text2, vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + recursion(index1 - 1, index2 - 1, text1, text2, dp);
        }
        return dp[index1][index2] = 0 + max(
            recursion(index1 - 1, index2, text1, text2, dp), 
            recursion(index1, index2 - 1, text1, text2, dp)
        );
    }

    int tabulation(string text1, string text2, vector<vector<int>> &dp){
        for(int index1 = 0; index1 < text1.size(); index1++){
            for(int index2 = 0; index2 < text2.size(); index2++){
                if(text1[index1] == text2[index2]){
                    int res = 1;
                    if(index1 - 1 >= 0 && index2 - 1 >= 0){
                        res += dp[index1 - 1][index2 - 1];
                    }
                    dp[index1][index2] = res;
                } else {
                    int resLeft = 0;
                    int resRight = 0;
                    if(index1 - 1 >= 0){
                        resLeft += dp[index1 - 1][index2];
                    }
                    if(index2 - 1 >= 0){
                        resRight += dp[index1][index2 - 1];
                    }
                    dp[index1][index2] = max(resLeft, resRight);
                }
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return tabulation(text1, text2, dp);
    }
};