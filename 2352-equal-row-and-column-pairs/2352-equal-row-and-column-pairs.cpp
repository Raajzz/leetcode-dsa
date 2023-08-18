class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> umap;
        for(int i=0; i<grid.size(); i++){
            string rowString = "";
            for(int j=0; j<grid.size(); j++){
                rowString += to_string(grid[i][j]) + "|";
            }
            umap[rowString]++;
        }
        
        int resCounter = 0;
        for(int i=0; i<grid.size(); i++){
            string colString = "";
            for(int j=0; j<grid.size(); j++){
                colString += to_string(grid[j][i]) + "|";
            }
            resCounter += umap[colString];
        }
        
        return resCounter;
    }
};