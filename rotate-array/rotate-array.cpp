class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // Sometimes just try to see if reversing stuff works, it's almost like figuring out the pattern to get what we want
        
        // here, reverse the first n-k terms, reverse the last k terms and then finally reverse the whole thing
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k );
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
        
        // won't work
        // ----------
        // int i=0;
        // k = k % nums.size();
        // int end_ptr = nums.size() - k;
        // int start_ptr = 0;
        // while(i<nums.size()){
        //     int j = 0;
        //     while(j<k){
        //         if(start_ptr >= nums.size()-1){
        //             return;
        //         }
        //         swap(nums[start_ptr], nums[end_ptr]);
        //         start_ptr++;
        //         end_ptr++;
        //         j++;
        //     }
        //     end_ptr = nums.size() - k;
        //     i++;
        //     if(start_ptr >= nums.size()-1){
        //         return;
        //     }
        // }
    }
};