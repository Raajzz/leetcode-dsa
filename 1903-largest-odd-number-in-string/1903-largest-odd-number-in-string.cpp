class Solution {
public:
    string largestOddNumber(string num) {
        int lastIndex = -1;
        for(int i=num.size(); i>=0; i--){
            if((num[i] - '0') % 2 != 0){
                lastIndex = i;
                break;
            }
        }
        return num.substr(0, lastIndex + 1);
    }
};