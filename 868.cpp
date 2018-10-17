/***********************

Careful of special cases in this problem.

O(1) time
O(1) space

***********************/

class Solution {
public:
    int binaryGap(int N) {
        if (N == 0) return 0;
        while (N % 2 == 0) N >>= 1;
        
        N >>= 1;
        bool onlyOne = true;
        int count = 1;
        int longest = 0;
        while (N) {
            if (N % 2 == 1) {
                longest = max(longest, count);
                count = 1;
                onlyOne = false;
            }
            else if (N % 2 == 0) {
                count++;                
            }
            N >>= 1;
        }
        
        return onlyOne ? 0 : longest;
    }
};