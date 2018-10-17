/***********************

Pretty straightforward. Each time it finds an island it will find the size of that entire island and set all of the 'land' to 0.
If that island is the largest it updates the value of the largest island.

O(nm) time
O(1) space

***********************/

class Solution {
public:
    void propogate(vector<vector<int>>& grid, int i, int j, int& area) {
        grid[i][j] = 0;
        area++;
        
        // Check 4 neighbors
        if (i-1 >= 0 && grid[i-1][j] == 1) propogate(grid, i-1, j, area);
        if (i+1 < grid.size() && grid[i+1][j] == 1) propogate(grid, i+1, j, area);
        if (j-1 >= 0 && grid[i][j-1] == 1) propogate(grid, i, j-1, area);
        if (j+1 < grid[0].size() && grid[i][j+1] == 1) propogate(grid, i, j+1, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                area = 0;
                if (grid[i][j] == 1) {
                    propogate(grid, i, j, area);
                    maxArea = max(area, maxArea);
                }                
            }
        }
        
        return maxArea;    
    }
};