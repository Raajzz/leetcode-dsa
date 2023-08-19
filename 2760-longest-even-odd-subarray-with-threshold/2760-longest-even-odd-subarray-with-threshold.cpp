class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int l = -1;
        int r = 0;
        int maxLen = 0;
        while(r < nums.size()){
            if(l == -1 && nums[r] % 2 == 0 && nums[r] <= threshold){
                l = r;
                r++;
            } else if ( l != -1 && (nums[r] % 2) != (nums[r - 1] % 2) && nums[r] <= threshold){
                r++;
            } else if(nums[r] > threshold || nums[r] % 2 == 1){
                r++;
                l = -1;
            } else {
                l = -1;
            }
            
            if(l != -1){
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }
};