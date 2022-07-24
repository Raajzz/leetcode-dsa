class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int z_ptr = 0;
      int nz_ptr = 0;
      while(z_ptr < nums.size() && nz_ptr < nums.size()){
        while(z_ptr < nums.size() && nums[z_ptr] != 0){
          z_ptr++;
        }
        while(nz_ptr < nums.size() && nums[nz_ptr] == 0){
          nz_ptr++;
        }
        if(z_ptr >= nums.size() || nz_ptr >= nums.size()){
          return;
        }
        if(z_ptr < nz_ptr){
          swap(nums[z_ptr], nums[nz_ptr]);
        } else {
          nz_ptr++;
        }
      }
    }
};