/***********************

Don't really like this problem. Most of the solutions people provide use outside knowledge of what numbers within this range of
possible bit counts (up to 20) could be prime. Finding primes is already sort of a problem in and of itself.

Apart from that, this is just a straightforward bit counting problem, which can apparently be done with a single command not used here:

int bitcount = __builtin_popcount(L++);

O(n) time
O(1) space

***********************/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        
        while (L <= R) {
            int bitcount = 0;            
            int num = L;
            
            while (num) {
                if (num % 2 == 1) bitcount++;
                num >>= 1;
            }
                        
            if (bitcount == 1) ;
            else if (bitcount == 2 || bitcount == 3) result++;            
            else if (bitcount % 2 && bitcount % 3) result++;
            
            L++;
        }
        
        return result;
    }
};