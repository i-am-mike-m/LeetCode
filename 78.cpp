class Solution {
public:
    void helper(vector<int>& nums, vector<int>& partial, vector<vector<int>>& res, int start) {
        if (start > nums.size()) return;
        res.push_back(partial);
        
        for (int i = start; i < nums.size(); i++) {
            partial.push_back(nums[i]);
            helper(nums, partial, res, i + 1);
            partial.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> partial;
        vector<vector<int>> res;
        helper(nums, partial, res, 0);
        
        return res;
    }
};