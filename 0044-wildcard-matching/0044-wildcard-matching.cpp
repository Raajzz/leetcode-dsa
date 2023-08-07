class Solution {
public:
    bool recursion(int i, int j, string s, string p, vector<vector<int>> &dp){
        if(i < 0 && j < 0){
            return true;
        } 
        if(i < 0 && j>=0){
            for(int count = 0; count <=j; count++){
                if(p[count] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(j < 0 && i >= 0){
            return false;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = recursion(i-1, j-1, s, p, dp);
        } else if (p[j] == '*'){
            return dp[i][j] = (recursion(i-1, j, s, p, dp) || recursion(i, j-1, s, p, dp));
        }
        return dp[i][j] = false;
    }
    
    bool tabulation(string s, string p){
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int j = 1; j<=p.size(); j++){
            bool  flag = true;
            for(int count = 1; count<=j; count++){
                if(p[count-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        

        
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j - 1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[s.size()][p.size()];
    }
    
    bool isMatch(string s, string p) {
        return tabulation(s, p);
    }
};