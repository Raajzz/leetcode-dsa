class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        
        while(end < nums.size()){
            if(nums[end] == 0){
                k--;
            }
            if(k < 0){
                if(nums[start] == 0){
                    k++;
                }
                start++;
            }
            end++;
        }
        
        // we don't need to do end - start + 1 because, when the loop ends, end will go
        // to nums.size(), i.e, it'll be one greater than the actual window size
        return end - start;
    }
};