class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        
        Brute Forced M*(N*Log(N)) algorithm,
        M -> total number of words in the given string vector
        N -> average length of a word
        
        */
        
        unordered_map<string, vector<string>> umap;
        
        for(int i=0; i<strs.size(); i++){
            string temp_str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            umap[strs[i]].push_back(temp_str);
        }
        
        vector<vector<string>> res;
        for(auto pair_val : umap){
            res.push_back(pair_val.second);
        }
        
        return res;
    }
};