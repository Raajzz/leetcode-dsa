class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> freqMap(n, 0);
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(auto vec: roads){
            freqMap[vec[0]]++;
            freqMap[vec[1]]++;
            graph[vec[0]][vec[1]] = 1;
            graph[vec[1]][vec[0]] = 1;
        }
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    res = max(res, freqMap[i] + freqMap[j] - graph[i][j]);
                }
            }
        }
        
        return res;
    }
};