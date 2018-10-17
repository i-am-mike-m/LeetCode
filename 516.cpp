class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp (size, vector<int> (size, 0));
        for (int i = 0; i < size; i++) { dp[i][i] = 1; }        
        
        for (int j = 1; j < size; j++) {
            for (int i = j-1; i >= 0; i--) {                
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1]; // Back-down diagonal index.
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        } 
        
        return dp[0][size - 1];
    }
};