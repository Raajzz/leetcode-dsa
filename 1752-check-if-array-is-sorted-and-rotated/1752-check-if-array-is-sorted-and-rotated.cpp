class Solution {
public:
    bool check(vector<int>& nums) {
        int inflictionPoint = 0;
        for(int i=0; i<nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                inflictionPoint++;
            }
        }
        if(inflictionPoint == 0){
            return true;
        } else if(inflictionPoint == 1){
            return nums[nums.size() - 1] <= nums[0];
        } 
        return false;
    }
};