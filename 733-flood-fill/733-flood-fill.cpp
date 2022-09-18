class Solution {
public:
//     My version for DFS causing some stack-overflow error which means therer's an infinite recursion issue.
//     void filler(vector<vector<int>> &image, int sr, int sc, vector<vector<bool>> &isVisited, int color, int m, int n){
//         if(isVisited[sr][sc]){
//             if(sr-1 >= 0 && sc-1>=0 && image[sr-1][sc-1] == image[sr][sc]){
//                 isVisited[sr-1][sc-1] = true;
//                 filler(image, sr-1, sc-1, isVisited, color, m, n);
//             }
//             if(sr-1>=0 && sc+1<n && image[sr-1][sc+1] == image[sr][sc]){
//                 isVisited[sr-1][sc+1] = true;
//                 filler(image, sr-1, sc+1, isVisited, color, m, n);   
//             }
//             if(sr+1 < m && sc-1 >=0 && image[sr+1][sc-1] == image[sr][sc]){
//                 isVisited[sr+1][sc-1] = true;
//                 filler(image, sr+1, sc-1, isVisited, color, m, n);   
//             } 
//             if(sr+1 < m && sc+1 <n && image[sr+1][sc+1] == image[sr][sc]){
//                 isVisited[sr+1][sc+1] = true;
//                 filler(image, sr+1, sc+1, isVisited, color, m, n);   
//             }
//             image[sr][sc] = color;
//         }
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         vector<vector<bool>> isVisited;
//         for(int i=0; i<image.size(); i++){
//             vector<bool> nestVisited(image[i].size(), false);
//             isVisited.push_back(nestVisited);
//         }
//         isVisited[sr][sc] = true;
//         filler(image, sr, sc, isVisited, color, image.size(), image[0].size());
//         return image;
//     }
    
    void filler(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int color, vector<int> &del_row, vector<int> &del_col){
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        for(int i=0; i<4; i++){
            if((row + del_row[i] >= 0) && (row + del_row[i] < m) && (col + del_col[i] >= 0) && (col + del_col[i] < n) && (image[row][col] == image[row + del_row[i]][col + del_col[i]]) && (ans[row + del_row[i]][col + del_col[i]] != color)){
                filler(row + del_row[i], col + del_col[i], image, ans, color, del_row, del_col);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
        vector<vector<int>> ans = image;
        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};
        filler(sr, sc, image, ans, color, del_row, del_col);
        return ans;
    }
};