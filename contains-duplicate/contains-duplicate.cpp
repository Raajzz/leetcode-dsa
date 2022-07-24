class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> umap;
        int counter = 0;
        for(auto val : nums){
            if(umap[val] != 0){
                return true;
            } else {
                umap[val] = true;
            }
        }
        return false;
    }
};