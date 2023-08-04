class Solution {
public:
    // I think the longest palindromic subsequence would be the longest common subsequence between that string and the reverse string
    
    int recursion(int index1, int index2, string s1, string s2, vector<vector<int>> &dp){
        
        if(index1 <= 0 || index2 <= 0){
            return 0;
        }
        
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        
        if(s1[index1 - 1] == s2[index2 - 1]){
            return dp[index1][index2] = 1 + recursion(index1 - 1, index2 - 1, s1, s2, dp); 
        }
        
        return dp[index1][index2] = 0 + max(
            recursion(index1 - 1, index2, s1, s2, dp),
            recursion(index1, index2 - 1, s1, s2, dp)
        );
        
    }
    
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
    
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        return tabulation(s1, s2, dp);
    }
};