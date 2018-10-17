class Solution {
public:
    void genHelper(int numRows, vector<vector<int>>& rows, int rowNum) {
        if (numRows == 0) return;        
        vector<int> current (rowNum + 1, 1);
        
        for (int i = 1; i < current.size() - 1 && rowNum >= 2; i++) {
            current[i] = rows[rowNum - 1][i - 1] + rows[rowNum - 1][i];
        }
        rows.push_back(current);
        
        genHelper(numRows - 1, rows, rowNum + 1);        
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
                
        genHelper(numRows, rows, 0);
        
        return rows;
    }
};