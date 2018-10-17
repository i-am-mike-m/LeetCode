class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int> pmap;
        unordered_map <char, int> smap;
        vector<int> res;
        for (auto each : p) pmap[each]++;
        for (int i = 0; i < p.size() - 1; i++) {
            smap[s[i]]++;
        }
        for (int i = p.size() - 1; i < s.size(); i++) {
            smap[s[i]]++;
            if (pmap.size() == smap.size()) { 
                if (smap == pmap) res.push_back(i - p.size() + 1);
            }
            smap[s[i - p.size() + 1]]--;
            if (smap[s[i - p.size() + 1]] == 0) smap.erase(s[i - p.size() + 1]);
        }
        return res;
    }
};