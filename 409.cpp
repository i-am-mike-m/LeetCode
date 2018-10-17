class Solution {
public:
    int longestPalindrome(string s) {
        int alpha[256] = {0};        
        int count = 0;
                        
        for (auto each : s) {
            alpha[each]++;
        }
        
        for (int i = 0; i < 256; i++) {
            if (alpha[i] > 0) {
                if (alpha[i] % 2 == 0) count += alpha[i];                
                else if (count % 2 == 0) count += alpha[i];                                
                else count += (alpha[i] - 1);
            }
        }
        
        return count;
    }
};