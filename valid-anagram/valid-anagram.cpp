class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> umap;
        for(auto val : s){
            umap[val]+=1;
        }
        for(auto val : t){
            int res_val = umap[val]-= 1;
            if(res_val == -1){
                return false;
            }
        }
        return true;
    }
};