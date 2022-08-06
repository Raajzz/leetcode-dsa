class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res_string = "";
        int strs_size = strs.size();
        int min_size = 200;
        
        for(int i=0; i<strs_size; i++){
            int curr_size = strs[i].size();
            if(curr_size < min_size){
                min_size = curr_size; 
            }
        }
        
        for(int i=0; i<min_size; i++){
            char com_char = strs[0][i];
            for(int j=0; j<strs_size; j++){
                if(strs[j][i] != com_char){
                    return res_string; 
                }
            }
            res_string += com_char;
        }
        
        return res_string;
    }
};