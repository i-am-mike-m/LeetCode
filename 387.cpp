class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int mindex = s.size();
        
        for (int i = 0; i < s.size(); i++) {
            auto search = map.find(s[i]);
            if (search != map.end()) map[s[i]] = -1;
            else map[s[i]] = i;
        }
        for (auto each : map) {
            if (each.second != -1 && each.second < mindex) mindex = each.second;
        }
        if (mindex == s.size()) return -1;
        return mindex;
    }
};