class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int size = nums.size();
        vector<vector<int>> dp (size, vector<int>(size, -1));
        for (int i = 0; i < size; i++) dp[i][i] = nums[i];
        
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i; j < size; j++) {
                if (dp[i][j] == -1) dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][size - 1] >= 0;
    }
};