class Solution {
public:
    bool isPowerOfThree(int n) {
        // brute-forced solution with for loop
        // if(n==0){
        //     return false;
        // }
        // int neg_mul = -1;
        // if(n>0){
        //     neg_mul = 1;   
        // }
        // while((long long int)((long long int)neg_mul*(long long int)n)%3 == 0){
        //    n /= 3; 
        // }
        // if(n == 1){
        //     return true;
        // }
        // return false;
        
        // simple solution using logarithms - Yet to complete
        
        if(n==0){
            return false;
        }
        int neg_mul = -1;
        if(n>0){
            neg_mul = 1;   
        }
        
        double log_value = (double)(log((long long int)neg_mul*(long long int)n)*1.0 / log(3)*1.0);
        int int_log_value = log_value;
        
        if(log_value - int_log_value > 0.0){
            return false;
        }
        return true;
    }
};