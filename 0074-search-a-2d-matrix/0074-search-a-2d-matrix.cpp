class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
      vector<int> first_elements;
      for(int i=0; i<matrix.size(); i++){
        first_elements.push_back(matrix[i][0]);
      }
      int search_index = upper_bound(first_elements.begin(), first_elements.end(), target) - first_elements.begin();
      if(search_index == 0){
        return false;
      }
      return binary_search(matrix[search_index-1].begin(), matrix[search_index-1].end(), target);
              
      // perform two binary search operations
      int m = matrix.size();
      int n = matrix[0].size();
      vector<int> first_col;
      for(int i=0; i<matrix.size(); i++){
          first_col.push_back(matrix[i][n-1]);
      }
      auto iter = lower_bound(first_col.begin(), first_col.end(), target);
      if(iter == first_col.end()){
          return false;
      }
      int search_pos = iter - first_col.begin();
      return binary_search(matrix[search_pos].begin(), matrix[search_pos].end(), target);
    }
};