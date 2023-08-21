class Solution {
public:
    string freqAlphabets(string s) {
        /********************************************************************
        
        - a different way or better way of doing this would be to start from the beginning of the string. Check of i + 2 is a '#' if that's the case then take the first character, convert to a number, multiply it by 10 and then convert it back to the respective character. If the i + 2th string isn't an '#' just convert the current character to its respective alphabet and be done with it.
        
        - Refer to the below solution
        
        string freqAlphabets(string s) {
            int n = s.length(), i = 0;
            string ans = "";
            while(i < n)
                if(i + 2 < n && s[i + 2] == '#') {
                    int ss = (s[i]-'0')*10 + (s[i+1]-'0');
                    ans += char(ss+'a'-1);
                    i += 3;
                }
                else {
                    ans += char(s[i]-'0'-1+'a');
                    i++;
                }
            }
            return ans;
        }
        
        ********************************************************************/
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