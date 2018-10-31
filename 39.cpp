class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& partial, vector<int>& nums, int target, int start) {
        if (target == 0) {
            res.push_back(partial); 
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i < nums.size(); i++) {                        
            partial.push_back(nums[i]);
            helper(res, partial, nums, target - nums[i], i);            
            partial.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> partial;
        helper(res, partial, nums, target, 0);
        
        return res;
    }
};