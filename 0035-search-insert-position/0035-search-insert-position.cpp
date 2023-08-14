class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // inorder to understand why returning `low` would always work, it is because every single time, at a particular point in time both low and high will point to the same index and so does the mid. At that instance, when low == high == mid, if the target becomes equal to the number then we move high before thereby ending the loop (low is the actual position to insert). If the target is greater then we move low to mid (low) + 1, thereby ending the loop and becomming the place to insert. If target is lesser, that is the right position to insert the element at.

        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while(high >= low){
            mid = low + (high - low)/2;
            if(target <= nums[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
        // at any and every instance high will be the one who fails that's why you should return low.
        // if Target is just bigger than the last number then low will point to last index + 1 while breaking low <= high
        // low is unironically more powerful
    }
};