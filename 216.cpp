class Solution {
public:
    void combine (int sum, vector<int>& partial, vector<vector<int>>& res, int start, int k) {
        if (sum < 0) return;
        if (k == 0) {
            if (sum == 0) res.push_back(partial);
            else return;
        } 
        
        for (int i = start; i < 9; i++) {                        
            partial.push_back(i + 1);
            combine(sum - (i + 1), partial, res, i + 1, k - 1);
            partial.pop_back();            
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> partial;
        combine(n, partial, res, 0, k);
                        
        return res;
    }
};