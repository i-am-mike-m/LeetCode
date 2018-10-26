class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp (A.size(), vector<int> (B.size(), 0));
        int largest = 0;
        
        for (int i = 0; i < dp[0].size(); i++) {
            for (int j = 0; j < dp.size(); j++) {
                if (B[i] == A[j]) {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) dp[i][j] += dp[i-1][j-1];
                    largest = max(largest, dp[i][j]);
                }
            }
        }
        
        return largest;
    }
};