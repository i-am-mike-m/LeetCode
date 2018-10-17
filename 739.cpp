class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> tempWithIndex;
        vector<int> res (T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!tempWithIndex.empty()) {
                pair<int,int> current = tempWithIndex.top();
                if (T[i] > current.first) {
                    tempWithIndex.pop();
                    res[current.second] = i - current.second;
                }
                else break;
            }
            tempWithIndex.push(make_pair(T[i], i));
        }
        
        return res;
    }
};