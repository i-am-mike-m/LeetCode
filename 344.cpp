/***********************

Too easy to require an explanation.

O(n) time
O(1) space

***********************/

class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size()-1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        
        return s;
    }
};