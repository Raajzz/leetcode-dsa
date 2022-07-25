class Solution {
public:
    bool isPalindrome(string s) {
        string new_string = "";
        for(auto val : s){
            if(isalnum(val)){
                new_string += tolower(val);
            }
        }
        for(int i=0; i<(new_string.size()/2); i++){
            if(new_string[i] != new_string[new_string.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};