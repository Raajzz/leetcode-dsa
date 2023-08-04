class Solution {
public:
    int tabulation(string word1, string word2, vector<vector<int>> &dp){
        for(int index1 = 1; index1 <= word1.size(); index1++){
            for(int index2 = 1; index2 <= word2.size(); index2++){
                if(word1[index1 - 1] == word2[index2 - 1]){
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];
                } else {
                    dp[index1][index2] = max(
                        dp[index1 - 1][index2],
                        dp[index1][index2 - 1]
                    );
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        return (word1.size() + word2.size() - (2 * tabulation(word1, word2, dp)));
    }
};