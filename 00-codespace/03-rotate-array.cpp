#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  for(int outer = 0; outer<nums.size()-k; outer+=k){
    for(int i=0; i<k; i++){
      swap(nums[outer+i], nums[nums.size()-k+i]);
    }
  }
  for(auto val : nums){
    cout << val << " ";
  }
  return 0;
}