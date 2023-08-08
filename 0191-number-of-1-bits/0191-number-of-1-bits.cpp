class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        int checkBit = 1;
        while(n){
            if(n & checkBit){
                counter++;
            }
            n = n >> 1;
        }
        return counter;
    }
};