class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.reserve(encoded.size()+1);
        ans.push_back(first);
        for(auto val : encoded){
            ans.push_back(first ^ val);
            first = first ^ val;
        }
        return ans;
    }
};