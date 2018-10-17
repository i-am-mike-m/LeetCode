class Solution {
public:
    void helper(string build, vector<string>& res, int to_open, int to_close) {
        if (to_open <= 0 && to_close <= 0) res.push_back(build);
        string closer = build;
        
        if (to_open > 0) {
            build += "(";
            helper(build, res, to_open - 1, to_close + 1);
        }
        if (to_close > 0) {
            closer += ")";
            helper(closer, res, to_open, to_close - 1);
        }        
    }
    
    vector<string> generateParenthesis(int n) {        
        vector<string> res;
        int to_open = n;
        int to_close = 0;
        helper("", res, to_open, to_close);
        
        return res;
    }
};