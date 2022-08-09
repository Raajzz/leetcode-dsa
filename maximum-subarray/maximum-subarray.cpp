class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int util_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(util_sum + nums[i] > nums[i]){
                util_sum += nums[i];
            } else {
                util_sum = nums[i];
            }
            if(util_sum > max_sum){
                max_sum = util_sum;
            }
        }   
        return max_sum;
    }
};