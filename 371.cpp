/***********************

This is a bit manipulation problem. It got downvoted a lot for that, but that doesn't make it a bad problem.

O(1) time
O(1) space

***********************/

class Solution {
public:
    int getSum(int a, int b) {
        int sum;
        while (b != 0) { // While there are no carry bits left to be added in.
            sum = a ^ b;        // This is the sum ignoring all carry bits.
            b = (a & b) << 1;   // This figures out the carry bits to keep adding in next loop.
            a = sum;            // This is the new running sum without the carry bits added in yet.
        }
        
        return sum;
    }
};