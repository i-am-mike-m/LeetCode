/***********************

The trick to doing this in O(n) time and O(1) space comes down to a bit manipulation trick. If you do an exclusive-or "^" to a number
two times with the same number, the net result is cancelled. That is, ((4 ^ 2) ^ 2) = 4. Since there is only one item in this array 
that isn't duplicated, starting with 0 and "^"-ing everything will leave you with the number that is not repeated.

This problem would be easy to do in O(n) time and O(n) space using an unordered_set. If a value is not in the set, you add it
to the set. If the value IS in the set, you remove it from the set. In the end, there will only be one value remaining in the set,
which is the answer.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0;
        for (int i = 0; i < nums.size(); i++) {
            number ^= nums[i];
        }
        
        return number;
    }
};