class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res (1,1);        
        while (rowIndex) {            
            res.push_back(1);
            for (int i = res.size()-2; i >= 1; i--) {
                res[i] = res[i] + res[i - 1];
            }            
            rowIndex--;
        }
        return res;
    }
};