/***********************

Another one of the worse problems on LeetCode. The first player to pick can always win if the number of stones is divisible by 4.
Otherwise they will always lose if the other player plays correctly.

O(1) time
O(1) space

***********************/

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4);
    }
};