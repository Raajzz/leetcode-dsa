class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> uset;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            if(uset.find(nums[i] + nums[j]) == uset.end()){
                uset.insert(nums[i] + nums[j]);
            }
            i++;
            j--;
        }
        return uset.size();
    }
};