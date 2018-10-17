class Solution {
public:
    string getStr(string& str, int& sIndex) {
        int start = sIndex;
        while (str[sIndex] != ' ' && sIndex < str.size()) { sIndex++; }
        return str.substr(start, sIndex - start);
    }
    
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp;
        unordered_set<string> beenMapped;
        int pIndex = 0;
        int sIndex = 0;
        while (sIndex < str.size() || pIndex < pattern.size()) {
            if (sIndex >= str.size() || pIndex >= pattern.size()) return false;
            string s = getStr(str, sIndex);
                        
            if (mp.find(pattern[pIndex]) == mp.end()) {
                if (beenMapped.find(s) != beenMapped.end()) return false;
                beenMapped.insert(s);
                mp.insert( { pattern[pIndex], s } );
            }
            else if (mp[pattern[pIndex]] != s) return false;
            pIndex++;
            sIndex++;
        }
        
        return true;
    }
};