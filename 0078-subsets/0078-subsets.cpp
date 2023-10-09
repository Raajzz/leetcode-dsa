class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // iterating form 0 to 2^n - 1
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0; i <= (1 << n) - 1; i++){
            vector<int> innerRes;
            for(int j=0; j<n; j++){
                if(i & (1 << j)){
                    innerRes.push_back(nums[j]);
                }
            }
            res.push_back(innerRes);
        }
        return res;
    }
};