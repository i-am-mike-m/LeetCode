/* DO THE FOLLOW UP STILL */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0, sSize = s.size();
        int tIndex = 0, tSize = t.size();
        
        while (tIndex < tSize && sIndex < sSize) {
            if (t[tIndex] == s[sIndex]) sIndex++;
            tIndex++;
        }
        return sIndex == sSize;
    }
};