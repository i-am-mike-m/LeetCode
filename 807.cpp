class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> topview (grid[0].size(), 0);
        vector<int> sideview (grid.size(), 0);
        int sum = 0;        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                topview[j] = max(topview[j], grid[i][j]);
                sideview[i] = max(sideview[i], grid[i][j]);
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int minview = min(topview[j], sideview[i]);
                if (grid[i][j] < minview) sum += minview - grid[i][j];
            }
        }
        return sum;    
    }
};