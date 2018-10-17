/***********************

x ^ y is the exclusive-or of x and y meaning that bits will only be set if they are set in only one of the two numbers.
% 2 == 1 tests whether the first bit is a 0 or a 1. If it is a 1, x and y differed in this bit.
>>= does a right bit shift of 1 bit. This places the 'next' bit in the first bit to be tested.
while(xory) will be false once all bits are 0 and no more bits need to be checked.

O(1) time
O(1) space

***********************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xory = x ^ y;
        int count = 0;
        
        while (xory) {
            if (xory % 2 == 1) count++;
            xory >>= 1;
        }
        
        return count;
    }
};