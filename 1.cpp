class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> comp;
        vector<int> res (2, -1);
        for (int i = 0; i < nums.size(); i++) {            
            auto iter = comp.find(target - nums[i]);
            if (iter == comp.end()) comp.insert( {nums[i], i} );
            else {
                res[0] = comp[target - nums[i]];
                res[1] = i;
                return res;
            }
        }
    }
};