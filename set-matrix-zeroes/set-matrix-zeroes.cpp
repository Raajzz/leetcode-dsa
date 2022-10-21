class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // sorta efficient O(Number of Zeros) solution
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    zeros.push_back(make_pair(i, j));
                }
            }
        }
        for(int counter=0; counter<zeros.size(); counter++){
            for(int i=0; i<m; i++){
                matrix[i][zeros[counter].second] = 0;
            }
            for(int j=0; j<n; j++){
                matrix[zeros[counter].first][j] =  0;
            }
        }
    }
};