/***********************

This is the bad stock problem. Just update buy price whenever lower and profit whenever prices are higher than buy.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentBuy = INT_MAX;
        int profit = 0;
        int currentSell = INT_MIN;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currentBuy) {
                currentBuy = prices[i];
            }
            if (prices[i] > currentBuy) {
                profit += (prices[i] - currentBuy);
                currentBuy = prices[i];
            }            
        }
        
        return profit;
    }
};