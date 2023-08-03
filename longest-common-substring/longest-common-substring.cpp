#include <bits/stdc++.h>

int lcs(string &str1, string &str2){
    // Write your code here.
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int maxi = INT_MIN;
    for(int index1 = 1; index1 <= str1.size(); index1++){
        for(int index2 = 1; index2 <= str2.size(); index2++ ){
            if(str1[index1 - 1] == str2[index2 - 1]){
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                maxi = max(maxi, dp[index1][index2]);
            } else {
                dp[index1][index2] = 0;
            }
        }
    }
    return maxi;
}
