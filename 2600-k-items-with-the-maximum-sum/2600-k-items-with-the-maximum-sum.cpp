class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        if(numOnes >= k){
            return k;
        }
        res += numOnes;
        k -= numOnes;
        
        if(numZeros >= k){
            return res;
        }
        k -= numZeros;
        
        if(numNegOnes >= k){
            res = res + k*-1;
            return res;
        }
        res -= numNegOnes;
        return res;
    }
};