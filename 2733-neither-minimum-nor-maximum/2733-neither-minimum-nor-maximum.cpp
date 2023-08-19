class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2){
            return -1;
        }
        int max = INT_MIN;
        int secondMax = INT_MIN;
        for(auto val: nums){
            if(val < secondMax){
                continue;
            }
            secondMax = val;
            if(secondMax > max){
                swap(max, secondMax);
            }
        }
        return secondMax;
    }
};