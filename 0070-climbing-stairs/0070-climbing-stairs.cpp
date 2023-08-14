class Solution {
public:
    unordered_map<int,int> map;
    
    int climbStairsSolver(int n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(!map[n]){
            map[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return map[n];
    }

    int climbStairsTabulation(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n){
        int prev = 1;
        int prev2 = 1;
        for(int i=2; i<=n; i++){
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};