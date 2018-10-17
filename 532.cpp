class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int,int> seen;
        int count = 0;
        for (auto each : nums) seen[each]++;                
        
        for (auto each : nums) {                                    
            int current = seen[each];
            if (k == 0) {
                if (current > 0 && current / 2 >= 1) count++;
            }                
            else {                
                int above = seen[each + k];
                int below = seen[each - k];
                if (min(current, below) > 0) count++;
                if (min(current, above) > 0) count++;
            }
            seen[each] = 0;            
        }
        
        return count;
    }
};