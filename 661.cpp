class Solution {
public:
    int getSmoothValue(vector<vector<int>> M, int x, int y) {
        int sum = M[x][y];
        int sizeX = M.size();
        int sizeY = M[0].size();
        int count = 1;
        
        if (x-1 >= 0 && y-1 >= 0) { sum += M[x-1][y-1]; count++; }
        if (x-1 >= 0) { sum += M[x-1][y]; count++; }
        if (x-1 >= 0 && y+1 < sizeY) { sum += M[x-1][y+1]; count++; }
        
        if (y-1 >= 0) { sum += M[x][y-1]; count++; }
        if (y+1 < sizeY) { sum += M[x][y+1]; count++; }
        
        if (x+1 < sizeX && y-1 >= 0) { sum += M[x+1][y-1]; count++; }
        if (x+1 < sizeX) { sum += M[x+1][y]; count++; }
        if (x+1 < sizeX && y+1 < sizeY) { sum += M[x+1][y+1]; count++; }
        
        sum = floor(sum / count);
        
        return sum;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(), 0));
        
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                res[i][j] = getSmoothValue(M, i, j);
            }
        }
        
        return res;
    }
};