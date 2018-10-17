/***********************

In ascii, 'A' comes before 'a' and you can change characters as if they were integers.

O(n) time
O(1) space

***********************/

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (isalpha(str[i]) && str[i] < 'a') str[i] += ('a' - 'A');
        }
        
        return str;
    }
};