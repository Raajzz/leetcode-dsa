#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board){
    // checking the row and column

    for(int i=0; i<9; i++){
        int arr_r[10] = {0};
        int arr_c[10] = {0};
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                if(arr_r[board[i][j] - '0'] == 0){
                    arr_r[board[i][j] - '0'] = 1;
                } else {
                    return false;
                }
                if(arr_c[board[j][i] - '0'] == 0){
                    arr_c[board[j][i] - '0'] = 1;
                } else {
                    return false;
                }
            }
        }
    }

    // checking the boxes

    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            int arr_cross[10] = {0};
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    if(board[k+i][l+j]!='.'){
                        if(arr_cross[board[k+i][l+j] - '0']==0){
                            arr_cross[board[k+i][l+j]] = 1;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;

}

int main(){
    
}