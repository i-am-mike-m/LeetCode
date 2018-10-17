/***********************

So many combinations of cases. Easy to get mixed up and miss something.

O(n) time
O(n) space

***********************/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (auto each : s) m[each]++;
    
        for (int i = 0; i < t.size(); i++) {
            if (m.find(t[i]) == m.end()) return t[i];
            else {
                m[t[i]]--;
                if (m[t[i]] == 0) m.erase(t[i]);
            }
        }
    }
};