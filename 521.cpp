/***********************

TERRIBLE PROBLEM. Absolute garbage.

Unless the two strings are equivalent, the longest UNCOMMON substring is simply the longer string. Such a trash problem.

O(1) time
O(1) space

***********************/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a != b) return max(a.size(), b.size());
        else return -1;
    }
};