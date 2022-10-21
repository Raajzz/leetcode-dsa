class Solution {
public:
    
    void calc_path(int a, int b, int &m, int &n, int &ups){
        if(a<=m && b<=n){
            if(a == m && b==n){
                ups++;
            } else if(a>=0 && b>=0){
                calc_path(a+1, b, m, n, ups);
                calc_path(a, b+1, m, n, ups);
            }
        }    
    }
    
    int uniquePaths(int m, int n) {
        int ups = 0;
        m-=1;
        n-=1;
        calc_path(0, 0, m, n, ups);
        return ups;
    }
    
};

class Solution {
public:
    
    int calc_path(int a, int b, int &m, int &n, map<pair<int,int>,int> &dp){
        if(dp[make_pair(m,n)]){
            return dp[make_pair(m,n)];
        }
        if(a<=m && b<=n){
            if(a == m && b==n){
                return 1;
            } else if(a>=0 && b>=0){
                return dp[make_pair(m,n)] = calc_path(a+1, b, m, n, dp) + calc_path(a, b+1, m, n, dp);
            }
        }
        return 0;
    }
    
    int uniquePaths(int m, int n) {
        int ups = 0;
        m-=1;
        n-=1;
        map<pair<int,int>,int> dp;
        return calc_path(0, 0, m, n, dp);
    }
    
};