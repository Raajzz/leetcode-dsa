class Solution {
public:
    string addBinary(string a, string b) {
        
        int remainder = 0;
        string res = "";
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while(i >= 0 && j >= 0){
            int sum = (a[i] - '0') + (b[j] - '0') + remainder;
            res += to_string(sum % 2);
            remainder = sum / 2;
            i--;
            j--;
            //cout << res << "\n";
        }
        
        while(i >= 0){
            int sum = (a[i] - '0') + remainder;
            res += to_string(sum % 2);
            remainder = sum / 2;
            i--;
            //cout << res << "\n";
        }
        
        while(j >= 0){
            int sum = (b[j] - '0') + remainder;
            res += to_string(sum % 2);
            remainder = sum / 2;
            j--;
            //cout << res << "\n";
        }        
        
        if(remainder == 1){
            res += '1';
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};