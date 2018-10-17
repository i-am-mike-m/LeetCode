/***********************

Pretty straightforward. Just manage the lowest price you've seen (to buy) and highest profit along the way.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowBuy = INT_MAX;
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowBuy) lowBuy = prices[i];
            else {
                if (maxProfit < prices[i] - lowBuy) maxProfit = prices[i] - lowBuy;
            }
        }
                    
        return maxProfit;
    }
};