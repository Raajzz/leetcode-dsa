class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(auto val: nums){
            freq[val]++;
        }
        
        int currMaxVal = 0;
        for(int i=0; i<101; i++){
            freq[i] += currMaxVal;
            currMaxVal = freq[i];
        }
        
        vector<int> res(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                res[i] = 0;
            } else {
                res[i] = freq[nums[i] - 1];
            }
        }
        
        return res;
        
    }
};