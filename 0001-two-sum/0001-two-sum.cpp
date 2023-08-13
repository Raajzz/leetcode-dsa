class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash-map
        vector<int> res;
        // <elementOfNums, indexOfTheElement>
        unordered_map<int,int> umap;
        for(int i=0; i<nums.size(); i++){
            if(umap.find(target - nums[i]) != umap.end()){
                res.push_back(i);
                res.push_back(umap[target - nums[i]]);
                break;
            } else {
                umap[nums[i]] = i;
            }
        }
        return res;
    }
};