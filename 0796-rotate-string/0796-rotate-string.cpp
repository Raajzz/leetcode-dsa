class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        for(int i=0; i<goal.size(); i++){
            if(compareStrings(s, goal, i)){
                return true;
            }
        }
        return false;
    }
    bool compareStrings(string s, string goal, int rotations){
        for(int i=0; i<s.size(); i++){
            if(s[i] != goal[(i + rotations)%goal.size()]){
                return false;
            }
        }
        return true;
    }
};