class Solution {
public:
    
    int tabulation(string s1, string s2, vector<vector<int>> &dp){
        for(int index1 = 1; index1 <= s1.size(); index1++){
            for(int index2 = 1; index2 <= s2.size(); index2++){
                if(s1[index1 - 1] == s2[index2 - 1]){
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = max(
                        dp[index1 - 1][index2],
                        dp[index1][index2 - 1]
                    );
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int lps = tabulation(s1, s2, dp);
        return s1.size() - lps;
    }
};