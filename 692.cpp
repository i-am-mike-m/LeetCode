class comp {
public:
    bool operator ()(pair<string,int> a, pair<string,int> b) {        
        if (a.second == b.second) {
            return a.first < b.first;
        }
        else return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> pq;
        for (auto each : words) map[each]++;
        for (auto each : map) {
            pair<string,int> p = make_pair(each.first, each.second);
            if (pq.size() < k) pq.push(p);
            else {
                pq.push(p);
                pq.pop();
            }
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};