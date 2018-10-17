/***********************

This is a very simple problem and needs no explanation.

O(n) time
O(1) space

***********************/

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> d;
        d['U'] = 1;
        d['D'] = -1;
        d['R'] = 1;
        d['L'] = -1;
        
        int count = 0;
        for (auto each : moves) count += d[each];
        
        return count == 0;
    }
};