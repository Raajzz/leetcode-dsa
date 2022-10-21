#include <bits/stdc++.h>
#define ld long double
#define ull unsigned long long int
#define ll long long int
#define uint unsigned int
#define str string
#define umap(a,b) unordered_map<a,b>
#define p(a,b) pair<a,b>
#define v(a) vector<a>

using namespace std;

void dp_check(vector<int>& nums, int idx, bool &res, unordered_map<int,int> &dp){
  if(dp[idx] == 0){
    if(idx == nums.size()-1){
      dp[idx] = 1; 
      res = true;
      return;
    } else if(idx < nums.size()-1){
      for(int i=1; i<=nums[idx]; i++){
        dp_check(nums, idx+i, res, dp);
      }
    } else {
      dp[idx] = -1;
    }
  } else if(dp[idx] == 1){
    res = true;
    return;
  }
}

bool canJump(vector<int>& nums) {
  bool res = false;
  dp_check(nums, 0, res);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  vector<int> vec = {3,2,1,0,4};
  cout << canJump(vec);
  return 0;
}

