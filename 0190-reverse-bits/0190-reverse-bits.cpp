class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int i = 32;
        while(i--){
            res <<= 1;
            res = res + n % 2;
            n >>= 1;
        }
        return res;
    }
};