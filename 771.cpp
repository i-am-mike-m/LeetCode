/***********************

Not too much explanation needed here.

O(J + S) time
O(1) space

***********************/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count[128] = {0};
        int total = 0;
        
        for (auto each : J) count[each]++;
        for (auto each : S) {
            if (count[each] != 0) total++;
        }
        
        return total;
    }
};