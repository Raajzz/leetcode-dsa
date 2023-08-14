class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++){
            int j = 0;
            int k = nums.size() - 1;
            while(j < k){
                if(j == i){
                    j++;
                    continue;
                }
                if(k == i){
                    k--;
                    continue;
                }
                int currRes = nums[i] + nums[j] + nums[k];
                if(currRes > 0){
                    k--;
                } else if (currRes < 0){
                    j++;
                } else {
                    vector<int> tempSt = {nums[i], nums[j], nums[k]};
                    sort(tempSt.begin(), tempSt.end());
                    st.insert(tempSt);
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};