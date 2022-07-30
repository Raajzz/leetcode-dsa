class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // the approach is like this, we need to find different segments / parts of the code such that there's maximum and a minimum, minimum < maximum, we buy at the minimum and we sell at the maximum
        int prices_size = prices.size();
        int buy = 0;
        int sell = 0;
        int profit = 0;
        int i = 0;
        while(i<prices_size-1){
            // finding the local continuous minima
            while(i<prices_size-1 && prices[i+1] <= prices[i]){
                i++;
            }
            buy = prices[i];
            
            // fiding the global continous maxima
            while(i<prices.size()-1 && prices[i+1] > prices[i]){
                i++;
            }
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};