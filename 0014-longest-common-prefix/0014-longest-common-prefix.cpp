class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int strsSize = strs.size();
        string ans = "";
        for(int i=0; i<min(strs[0].size(), strs[strsSize - 1].size()); i++){
            if(strs[0][i] != strs[strsSize - 1][i]){
                break;
            } else {
                ans += strs[0][i];
            }
        }
        return ans;
    }
};