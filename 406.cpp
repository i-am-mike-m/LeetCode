bool comp (pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res;
        sort(people.begin(), people.end(), comp);
        for (auto each : people) res.insert(res.begin() + each.second, each);
        
        return res;
    }
};