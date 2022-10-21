class Solution {
public:
    bool isPowerOfThree(int n) {
        // brute-forced solution with for loop
        if(n==0){
            return false;
        }
        int neg_mul = -1;
        if(n>0){
            neg_mul = 1;   
        }
        while((long long int)((long long int)neg_mul*(long long int)n)%3 == 0){
           n /= 3; 
        }
        if(n == 1){
            return true;
        }
        return false;
    }
};