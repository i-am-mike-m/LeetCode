class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp (piles.size(), vector<int>(piles.size(), -1));
        int size = piles.size();
        
        for (int i = 0; i < size; i++) dp[i][i] = piles[i];
        
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i; j < size; j++) {
                if (dp[i][j] == -1) dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j - 1]);
            }
        }
        
        return dp[0][piles.size()-1] > 0;
    }
};