class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> primeCheck(33, false);
        primeCheck[2] = true;
        primeCheck[3] = true;
        primeCheck[5] = true;
        for(int i=2; i<=32; i++){
            if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0){
                primeCheck[i] = true;
            }
        }
        int resCounter = 0;
        for(int i=left; i<=right; i++){
            int bitCounter = 0;
            int bitHelper = i;
            while(bitHelper){
                if(bitHelper % 2 == 1){
                    bitCounter++;
                }
                bitHelper >>= 1;
            }
            if(primeCheck[bitCounter]){
                resCounter++;
            }
        }
        return resCounter;
    }
};