class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        
        bool check_row = false;
        bool check_col = false;
        
        for(int i=0; i<row_size && !check_row; i++){
            if(matrix[i][0] == 0){
                check_row = true;
            }
        }
        
        for(int j=0; j<col_size && !check_col; j++){
            if(matrix[0][j] == 0){
                check_col = true;
            }
        }
        
        for(int i=1; i<row_size; i++){
            for(int j=1; j<col_size; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=row_size-1; i>=0; i--){
            for(int j=col_size-1; j>=0; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(check_row){
            for(int i=0; i<row_size; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(check_col){
            for(int j=0; j<col_size; j++){
                matrix[0][j] = 0;
            }
        }
        
    }
};