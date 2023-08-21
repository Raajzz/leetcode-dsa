class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.size() - 1;
        string res = "";
        while(i >= 0){
            if(s[i] == '#'){
                string tempString = "";
                tempString += s[i - 1];
                tempString += s[i - 2];
                reverse(tempString.begin(), tempString.end());
                res += (char)(96 + stoi(tempString));
                i -= 3;
            } else {
                res += (char)(96 + (s[i--] - '0'));
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};