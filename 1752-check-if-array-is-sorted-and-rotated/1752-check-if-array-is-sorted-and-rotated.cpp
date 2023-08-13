class Solution {
public:
    bool check(vector<int>& nums) {
        // int flag = 0;
        // for(int i=0; (i<nums.size() - 1) && (flag != 2); i++){
        //     if(flag == 0 || flag == 1){
        //         if( nums[i] > nums[i+1] ){
        //             flag++;
        //         }
        //     }
        // }
        // return (flag == 0 || flag == 1);
        
        // infliction point finder
        
        int inflictionPoint = -1;
        int flag = 0;
        for(int i=0; i<nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                flag += 1;
                inflictionPoint = i;
            }
        }
        
        if(flag > 1){
            return false;
        }
        
        if(inflictionPoint == -1){
            return true;
        } else {
            for(int i=inflictionPoint+1; i<nums.size() - 1; i++){
                if(nums[i] > nums[i + 1]){
                    return false;
                }
            }
            if(nums[nums.size() - 1] > nums[0]){
                return false;
            }
            for(int i=0; i<inflictionPoint - 1; i++){
                if(nums[i] > nums[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};