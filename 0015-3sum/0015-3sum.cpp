class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> res;
        while(i < nums.size()){
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int currRes = nums[i] + nums[j] + nums[k];
                if(currRes > 0){
                    k--;
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                } else if (currRes < 0){
                    j++;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
            i++;
        }
        return res;
    }
};