class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr_low = 0;
        int ptr_mid = 0;
        int ptr_high = nums.size()-1;
        while(ptr_mid <= ptr_high){
            if(nums[ptr_mid] == 0){
                swap(nums[ptr_low], nums[ptr_mid]);
                ptr_low++;
                ptr_mid++;
            } 
            else if(nums[ptr_mid] == 1){
                ptr_mid++;
            }
            else if(nums[ptr_mid] == 2){
                swap(nums[ptr_mid], nums[ptr_high]);
                ptr_high--;
            }
        }
    }
};