class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        } else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int max = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        int intMinFlag = 0;
        for(auto val: nums){
            if(val == INT_MIN){
                intMinFlag = 1;
            }
            if(val < thirdMax || val == thirdMax || val == secondMax || val == max){
                continue;
            }
            thirdMax = val;
            if(thirdMax > secondMax){
                swap(thirdMax, secondMax);
            }
            if(secondMax > max){
                swap(secondMax, max);
            }
        }
        if(intMinFlag == 1 && secondMax == INT_MIN){
            return max;
        }
        if(intMinFlag == 0 && thirdMax == INT_MIN){
            return max;
        }
        return thirdMax;
    }
};