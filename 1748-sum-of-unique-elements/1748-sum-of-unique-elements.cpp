class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto val : nums){
            umap[val]++;
        }
        int sum = 0;
        for(auto map_val:umap){
            if(map_val.second == 1){
                sum += map_val.first;
            }
        }
        return sum;
    }
};