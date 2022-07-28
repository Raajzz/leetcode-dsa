#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> nums = {1,3,12,0,0};
  int z_ptr = 0;
  int nz_ptr = 0;
  while(z_ptr < nums.size() && nz_ptr < nums.size()){
    while(nums[z_ptr] != 0){
      z_ptr++;
    }
    while(nums[nz_ptr] == 0){
      nz_ptr++;
    }
    if(z_ptr >= nums.size() || nz_ptr >= nums.size()){
      for(auto val : nums){
        cout << val << " ";
      }
      exit(0);
    }
    if(z_ptr < nz_ptr){
      swap(nums[z_ptr], nums[nz_ptr]);
    } else {
      nz_ptr++;
    }
  }
  for(auto val : nums){
    cout << val << " ";
  }
}