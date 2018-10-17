class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = mp.find(nums[i]);
            if (iter == mp.end()) mp.insert( { nums[i], vector<int>(1, i) } );
            else iter->second.push_back(i);
        }
        for (auto each : mp) {
            for (int i = 0; i < each.second.size(); i++) {
                for (int j = i + 1; j < each.second.size(); j++) {
                    if (abs(each.second[j] - each.second[i]) <= k) return true;
                }
            }
        }
        
        return false;
    }    
};