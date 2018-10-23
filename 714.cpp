class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) return 0;        
        int size = prices.size(); 
        vector<int> buying (size, 0);
        vector<int> selling (size, 0);
        
        buying[0] = -prices[0];
        for (int i = 1; i < size; i++) {
            buying[i] = max(buying[i - 1], selling[i - 1] - prices[i]);
            selling[i] = max(selling[i - 1], buying[i - 1] + prices[i] - fee);
        }
        
        return selling[size - 1];
    }
};