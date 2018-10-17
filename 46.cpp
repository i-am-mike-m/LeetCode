/***********************

This is an algorithms trick called "backtracking" where you make a change to an input, do a recursive call with the change and
then undo the change as the stack unwinds.

O(n!) time
O(n) space

***********************/

class Solution {
public:
    void permHelper(vector<vector<int>>& results, vector<int>& nums, int start) {
        if (start == nums.size()-1) {
            results.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permHelper(results, nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        
        permHelper(results, nums, 0);
        
        return results;
    }
};