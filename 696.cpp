/***********************

How long it takes for a run to change characters is the key!

O(n) time
O(1) space

***********************/

class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.size() == 0) return 0;        
        int size = s.size();
        int currentRun = 1;
        int lastRun = 0;
        int count = 0;
                
        for (int i = 0; i < size-1; i++) {
            if (s[i+1] == s[i]) currentRun++;
            else {                
                count += min(lastRun, currentRun);
                lastRun = currentRun;
                currentRun = 1;
            }
        }
        count += min(lastRun, currentRun);
        
        return count;
    }
};