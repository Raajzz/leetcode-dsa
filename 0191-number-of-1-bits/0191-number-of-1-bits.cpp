class Solution {
public:
    // kinda a brute forced version
    // TC - O(32)
    // int hammingWeight(uint32_t n) {
    //     int counter = 0;
    //     int checkBit = 1;
    //     while(n){
    //         if(n & checkBit){
    //             counter++;
    //         }
    //         n = n >> 1;
    //     }
    //     return counter;
    // }
    
    // optimized
    // TC - O(Number of 1s)
    int hammingWeight(uint32_t n) {
        int counter = 0;
        while(n){
            n = n & (n-1);
            counter++;
        }
        return counter;
    }
};