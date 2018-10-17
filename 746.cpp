class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minusTwo = 0;
        int minusOne = 0;
        
        for (int i = 2; i <= cost.size(); i++) {
            int next = min(minusTwo + cost[i-2], minusOne + cost[i-1]);
            minusTwo = minusOne;
            minusOne = next;
        }
        
        return minusOne;
    }
};