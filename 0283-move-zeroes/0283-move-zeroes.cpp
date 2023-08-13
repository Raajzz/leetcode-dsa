class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPtr = 0;
        int numPtr = 0;
        while(zeroPtr < nums.size() && numPtr < nums.size()){
            while(zeroPtr < nums.size() && nums[zeroPtr] != 0){
                cout << zeroPtr << " ";
                zeroPtr++;
            }
            cout << "\n";
            numPtr = zeroPtr;
            while(numPtr < nums.size() && nums[numPtr] == 0){
                numPtr++;
            }
            cout << zeroPtr << " " << numPtr << "\n";
            if(numPtr >= nums.size() || zeroPtr >= nums.size()){
                break;
            }
            swap(nums[numPtr], nums[zeroPtr]);
        }
    }
};