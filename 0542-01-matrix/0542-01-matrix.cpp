class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //          rowPos, colPos, currValue 
        vector<vector<bool>> isVisited(mat.size(), vector<bool>(mat[0].size(), false));
        queue<pair<pair<int, int>, int>> que;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    que.push(make_pair(make_pair(i, j), 0));
                    isVisited[i][j] = true;
                }
            }
        }

        vector<int> dRow = {-1, +1, 0, 0};
        vector<int> dCol = {0, 0, -1, +1};

        while(!que.empty()){
            int queSize = que.size();
            while(queSize--){
                pair<pair<int,int>, int> queElement = que.front();
                que.pop();
                int rowPos = queElement.first.first;
                int colPos = queElement.first.second;
                int currValue = queElement.second;

                for(int i=0; i<dRow.size(); i++){
                    int newRowPos = rowPos + dRow[i];
                    int newColPos = colPos + dCol[i];
                    if(newRowPos >= 0 && newRowPos < mat.size() && newColPos >= 0 && 
                    newColPos < mat[0].size() && !isVisited[newRowPos][newColPos]){
                        mat[newRowPos][newColPos] = currValue + 1;
                        que.push(make_pair(make_pair(newRowPos, newColPos), currValue + 1));
                        isVisited[newRowPos][newColPos] = true;
                    }
                }

            }
        }
        return mat;
    }
};