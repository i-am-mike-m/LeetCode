/***********************

This is a tricky problem that's actually not too bad once you see the trick!

O(n) time
O(n) space

***********************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        vector<int> forward (prices.size(), 0);
        vector<int> backward (prices.size(), 0);
        
        int minBuyFwd = INT_MAX;
        int maxProfitFwd = 0;
        int maxSellBack = INT_MIN;
        int maxProfitBack = 0;
        
        // Forward Loop - First Buy
        for (int i = 0; i < prices.size(); i++) {
            minBuyFwd = min(minBuyFwd, prices[i]);
            maxProfitFwd = max(maxProfitFwd, prices[i]-minBuyFwd);
            forward[i] = maxProfitFwd;            
        }
        // Backward Loop - Second Buy
        for (int i = prices.size()-1; i >= 0; i--) {
            maxSellBack = max(maxSellBack, prices[i]);
            maxProfitBack = max(maxProfitBack, maxSellBack-prices[i]);
            backward[i] = maxProfitBack;
        }
        // Optimize Loop
        int bestProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            bestProfit = max(bestProfit, forward[i]+backward[i]);
        }
        
        return bestProfit;
    }
};