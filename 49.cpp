class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {        
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        
        for (auto each : strs) {
            string temp = each;
            sort(temp.begin(), temp.end());            
            if (map.find(temp) == map.end()) {
                vector<string> v;
                v.push_back(each);
                map[temp] = v;
            }
            else {
                map[temp].push_back(each);
            }
        }
        for (auto each : map) {
            res.push_back(each.second);
        }
        return res;
    }
};