/***********************

This is ultimately a base-conversion type problem with base = 26.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int titleToNumber(string s) {
        if (s.size() == 0) return 0;
        
        int sum = 0;
        int convert = 1 - 'A';
        int power = s.size() - 1;
        
        for (int i = 0; i < s.size(); i++) {
            int current = s[i] + convert;
            sum += current * pow(26, power);
            power--;
        }       
        
        return sum;
    }
};