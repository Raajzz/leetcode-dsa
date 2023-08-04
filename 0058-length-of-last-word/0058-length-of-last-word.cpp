class Solution {
public:
    int lengthOfLastWord(string s) {
        string res;
        int spaceAllowFlag = 1;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' ' && spaceAllowFlag == 0){
                break;
            } else if (s[i] != ' '){
                spaceAllowFlag = 0;
                res += s[i];
            }
        }
        return res.size();
    }
};