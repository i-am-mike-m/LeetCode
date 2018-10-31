class Solution {
public:
    void helper(int n, int k, vector<vector<int>>& res, vector<int>& partial, int start) {
        if (k == 0) {
            res.push_back(partial);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            partial.push_back(i);
            helper(n, k - 1, res, partial, i + 1);
            partial.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> partial;
        helper(n, k, res, partial, 1);
        
        return res;
    }
};