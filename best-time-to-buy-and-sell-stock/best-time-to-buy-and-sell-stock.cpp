class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // approach 1
        int low = 0;
        int high = 1;
        int profit = 0;
        int prices_size = prices.size();
        while(high < prices_size){
            if(prices[high] < prices[low]){
                low = high;
            }
            if(prices[high] - prices[low] > profit){
                profit = prices[high] - prices[low];
            }
            high++;
        }
        return profit;
    }
};