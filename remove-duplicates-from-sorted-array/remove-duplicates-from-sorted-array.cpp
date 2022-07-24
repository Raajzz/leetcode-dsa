class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr_1 = 0;
        int ptr_2 = 0;
        while(ptr_1 < nums.size() && ptr_2 < nums.size()){
            if(nums[ptr_1] == nums[ptr_2]){
                ptr_2++;
            } else {
                nums[++ptr_1] = nums[ptr_2++];
            }
        }
        return ptr_1+1;
    }
};