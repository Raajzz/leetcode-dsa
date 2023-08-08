class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n == 0){
            return false;
        } else if (n == 1){
            return true;
        }
        
        bool flag = n & 1;
        while(n){
            n >>= 1;
            if(!(flag ^ (n & 1))){
                return false;
            }
            flag = n & 1;
        }
        return true;
    }
};