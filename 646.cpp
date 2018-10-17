bool compare (vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return 0;
        sort(pairs.begin(), pairs.end(), compare);
        
        int a = pairs[0][1];
        int length = 1;
        
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > a) {
                length++;
                a = pairs[i][1];
            }
        }
        
        return length;
    }
};