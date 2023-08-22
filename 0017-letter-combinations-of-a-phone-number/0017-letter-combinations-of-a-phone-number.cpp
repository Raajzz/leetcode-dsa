class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> oldStringArray;
        if(digits.size() == 0){
            return oldStringArray;
        }
        vector<string> mapArray{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string currString = mapArray[digits[0] - '0'];
        for(int i=0; i<currString.size(); i++){
            oldStringArray.push_back(string(1, currString[i]));
        }
        for(int i=1; i<digits.size(); i++){
            vector<string> newStringArray;
            int currNum = digits[i] - '0';
            string currString = mapArray[currNum];
            for(int j = 0; j<oldStringArray.size(); j++){
                for(int k = 0; k<currString.size(); k++){
                    newStringArray.push_back(oldStringArray[j] + currString[k]);
                }
            }
            oldStringArray = newStringArray;
        }
        return oldStringArray;
    }
};