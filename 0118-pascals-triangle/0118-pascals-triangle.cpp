class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        pt.reserve(numRows);
        for(int i=0; i<numRows; i++){
            pt.push_back({1});
        }
        if(numRows == 1){
            return pt;
        }
        pt[1].push_back(1);
        for(int i=2; i<numRows; i++){
            int j=0; 
            int k=1;
            while(k<i){
                pt[i].push_back(pt[i-1][j] + pt[i-1][k]);
                j++;
                k++;
            }
            pt[i].push_back(1);
        }
        return pt;
    }
};