class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size() * (nums.size() + 1))/2;
        int temp_sum = 0;
        for(auto val : nums){
            temp_sum += val;
        }
        return sum - temp_sum;
    }
};