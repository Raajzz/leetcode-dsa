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
    
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        tabulation(str1, str2, dp);    
        int i = str1.size();
        int j = str2.size();
        string res;
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                res += str1[i - 1];
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]){
                res += str1[i - 1];
                i = i - 1;
            } else {
                res += str2[j - 1];
                j = j - 1;
            }
        }
        while(i > 0){
            res += str1[i-1];
            i--;
        }
        while(j > 0){
            res += str2[j-1];
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};