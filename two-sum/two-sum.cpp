class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(auto val : nums){
            umap[val] = target - val;
        }
        vector<int> same_vec;
        vector<int> diff_vec;
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] == target - nums[i]){
                same_vec.push_back(i);
            } else if(nums[i] == umap[target - nums[i]]){
                diff_vec.push_back(i);
            }
            
            if(same_vec.size() == 2){
                return same_vec;
            }
            if(diff_vec.size() == 2){
                return diff_vec;
            }
            
        }
        return {};
    }
};