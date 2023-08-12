class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);
        int ans = 0;
        for(auto chr: s){
            if(chr >= 'a' && chr <= 'z'){
                lower[chr - 'a'] += 1;
            } else {
                upper[chr - 'A'] += 1;
            }
        }
        for(int i=0; i<26; i++){
            ans += (upper[i] / 2) * 2;
            ans += (lower[i] / 2) * 2;
        }
        if(ans < s.size()){
            ans += 1;
        }
        return ans;
    }
};