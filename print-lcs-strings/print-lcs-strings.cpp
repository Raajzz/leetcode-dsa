
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lcs(string text1, string text2, vector<vector<int>> &dp){
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


int main(){
	string text1 = "bdgek";
	string text2 = "abcde";
	vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
	lcs(text1, text2, dp);
	int i = text1.size() - 1;
	int j = text2.size() - 1;
	string res;
	while(i >= 0 && j >= 0){
		if(text1[i] == text2[j]){
			res += text1[i];
			i--;
			j--;
		} else if (dp[i-1][j] > dp[i][j-1]){
			i--;
		} else {
			j--;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
