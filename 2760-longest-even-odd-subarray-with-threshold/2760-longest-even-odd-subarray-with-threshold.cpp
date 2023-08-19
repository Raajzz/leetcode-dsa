class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int l = -1;
        // r would be the variable that iterates through the nums array
        int r = 0;
        int maxLen = 0;
        while(r < nums.size()){
            if(l == -1 && nums[r] % 2 == 0 && nums[r] <= threshold){
                // This condition is to make sure, the first element of the subarray is an even number and is less than the threshold
                l = r;
                r++;
            } else if ( l != -1 && (nums[r] % 2) != (nums[r - 1] % 2) && nums[r] <= threshold){
                // This condition is to make sure the constraints are satisfied [Even/Odd pair and <= threshold] 
                r++;
            } else if(nums[r] > threshold || nums[r] % 2 == 1){
                // The below two conditions are to check if the failed r is the start of a new subarray

                // This condition is to check whether we should increment the r variable or not. If the result constraints fail due to an odd number or the current value at the position of r is greater than threshold then there is no possibility for that positioned to be the start of the subarray again
                r++;
                l = -1;
            } else {
                // This condition is when our cases fail due to an even number, if this is just an even number, this position might be our start of a new subarray
                l = -1;
            }
            
            if(l != -1){
                // r - l because, at every single instance r will be incremented to the next possible index
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }
};