class compare {
    public:
        bool operator() (pair<int,int> a, pair<int,int> b) {
            return a.second < b.second;
        }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numCount;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<int> res;
        
        for (auto each : nums) numCount[each]++;
        for (auto each : numCount) pq.push(make_pair(each.first, each.second));
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};