/***********************

Excellent tree problem!

O(n) time
O(n) space

***********************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m;
        
        for (auto each : s) {
            m[each]++;
        }
        
        for (auto each : t) {
            m[each]--;
            if (m[each] == 0) m.erase(each);
        }
        
        return m.empty();
    }
};