class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // finding the point where we can introduce a change
        int index = -1;
        for(int i=nums.size() - 1; i>0; i--){
            if(nums[i] > nums[i-1]){
                index = i - 1;
                break;
            }
        }
        
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // swaping the point of change with the nearest greater number to the right of the point of change
        
        int justMax = INT_MAX;
        int justMaxIndex = 0;
        int valueAtPoint = nums[index];
        for(int i = index; i<nums.size(); i++){
            if(nums[i] > valueAtPoint){
                justMax = min(nums[i], justMax);
                justMaxIndex = i;
            }
        }
        swap(nums[index], nums[justMaxIndex]);
        reverse(nums.begin() + index + 1, nums.end());
    }
};