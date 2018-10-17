class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> pool;
        for (auto each : nums) pool[each]++;
        int maxCount = 0;
                  
        for (auto each : pool) {                            
            int up = 0;
            int down = 0;
            if (pool.find(each.first + 1) != pool.end()) up = each.second + pool[each.first + 1];
            if (pool.find(each.first - 1) != pool.end()) down = each.second + pool[each.first - 1];
              
            int count = max(up, down);
            maxCount = max(maxCount, count);                        
        }
        
        return maxCount;
    }
};