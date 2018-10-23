class Solution {
public:
    int numTrees(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = dp[1] = 1;
                
        for (int i = 2; i <= n; i++) {
            int count = 0;
            for (int j = 0; j < i; j++) {
                int before = 0 + j;
                int after = i - j - 1;
                count += dp[before] * dp[after];
            }
            dp[i] = count;            
        }
        
        return dp[n];
    }
};