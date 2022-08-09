class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime_vec(n, false);
        if(n<=2){
            return 0;
        }
        
        prime_vec[0] = true;
        prime_vec[1] = true;
        prime_vec[2] = false;
        for(int i=3; i<n; i+=2){
            if(prime_vec[i] == false) {
                for(long long int j = (long long int)i*i; j<n; j+=i){
                    prime_vec[j] = true;
                }   
            }
        }
        int res = 1;
        for(int i=3; i<n; i+=2){
            if(prime_vec[i] == false){
                res++;
            }
        }
        return res;
    }
};