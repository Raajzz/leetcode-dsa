// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int mid_function(int min, int max){
        return (min + ceil((max - min)/2));
    }
    
    int firstBadVersion(int n) {
        int min = 1;
        int max = n;
        int mid = mid_function(min, max);
        while(min<max){
            if(!isBadVersion(mid)){
                min = mid + 1;
                mid = mid_function(min, max);
            } else {
                if(mid == 1 || !isBadVersion(mid - 1)){
                    return mid;
                }
                max = mid - 1;
                mid = mid_function(min, max);
            }
        }
        // if(!isBadVersion(mid)){
        //     min = mid + 1;
        //     mid = mid_function(min, max);
        // } else {
        //     if(mid == 1 || !isBadVersion(mid - 1)){
        //         return mid;
        //     }
        // }
        return mid;
    }
};