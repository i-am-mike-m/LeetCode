/***********************

Straightforward classic hash map problem.

O(n+m) time
O(n) space where n is the number of chars in the ransom note.

***********************/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;       
        for (auto each : ransomNote) map[each]++;
        
        for (auto each : magazine) {
            if (map.find(each) != map.end()) {
                map[each]--;
                if (map[each] == 0) map.erase(each);
            }
        }
        
        return map.empty();
    }
};