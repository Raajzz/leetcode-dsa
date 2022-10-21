#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices){
    int profit = 0;
    for(int i=0; i<prices.size()-1; i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j] - prices[i] > profit){
                profit = prices[j] - prices[i];
            }
        }
    }
    return profit;
}

int main(){
    cout << maxProfit({7, 1, 5, 3, 6, 4});
    return 0;
}