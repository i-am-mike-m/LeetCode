/***********************

This could be improved upon slightly, though not in overal complexity. Instead of checking all four surrounding squares each time we
can instead only look up and left from the current square and just remove 2 borders at a time. It's better, but doesn't improive the
time complexity anyway.

O(nm) time - n is the number of rows and m is the number of columns
O(1) space

***********************/

class Solution {
public:
    int checkSurrounding(vector<vector<int>>& grid, int i, int j) {
        int dupes = 0;
        if (i-1 >= 0 && i-1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i-1][j] == 1) dupes++;
        if (i+1 >= 0 && i+1 < grid.size() && j >= 0 && j < grid[0].size() && grid[i+1][j] == 1) dupes++;
        if (i >= 0 && i < grid.size() && j-1 >= 0 && j-1 < grid[0].size() && grid[i][j-1] == 1) dupes++;
        if (i >= 0 && i < grid.size() && j+1 >= 0 && j+1 < grid[0].size() && grid[i][j+1] == 1) dupes++;
        return dupes;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int borders = 0;
                
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    borders += 4;
                    borders -= checkSurrounding(grid, i, j);                    
                }
            }
        }
        
        return borders;
    }
};