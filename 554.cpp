class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> commonSums;
        for (auto each : wall) {
            int sum = 0;
            for (int i = 0; i < each.size() - 1; i++) {
                sum += each[i];
                commonSums[sum]++;
            }
        }
        int count = 0;
        int index = 0;
        for (auto each : commonSums) {
            if (each.second > count) { count = each.second; }
        }
        return wall.size() - count;
    }
};