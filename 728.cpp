/***********************

This is a fairly odd problem. For each number between the bounds you use the standard % and / actions to determine each digit.
Then you determine whether the number is divisible by each of it's digits and add it to the results if so.

O(n) time
O(n) space

***********************/

class Solution {
public:
    bool isSelfDiv(int x) {
        vector<int> digits;
        int temp = x;
        while (temp) {
            if (temp % 10 == 0) return false;
            digits.push_back(temp % 10);
            temp /= 10;
        }
        for (auto each : digits) {
            if (x % each != 0) return false;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> results;
        for (int i = left; i <= right; i++) {
            if (isSelfDiv(i)) results.push_back(i);
        }
        return results;
    }
};