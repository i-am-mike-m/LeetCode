/***********************

Create a mask with all 1 bits by doing ~0, or, not zero.
While (num & mask) means that as long as num & mask is not zero, shift the mask left. This results in all 1's in bits larger than
those used by num and all 0's in bits potentially used by num.
Returning ~mask and ~num will flip all the bits in num but then doing & (and) with the flipped mask, all bits larger than those 
used in the original num will be flipped back to 0.

O(1) time
O(1) space

***********************/

class Solution {
public:
    int findComplement(int num) {     
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};