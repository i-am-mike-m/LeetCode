/***********************

This is O(1) time because a 32-bit number will never take more than 32 actions to come to a solution.

The trick here is to use (n % 2) to get the value of the first bit and then to continually bit shift right one bit at a time,
checking the new first bit against the former and then updating the variable used to track the former. If a short-circuit failure
is never encountered (IE two simultaneous bits share the same value), you may return true.

O(1) time
O(1) space

***********************/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int current = n % 2;
        
        while (n) {
            n >>= 1;
            if (current == (n % 2)) return false;
            else current = n % 2;
        }
        
        return true;
    }
};