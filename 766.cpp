/***********************

The wording of this problem is very confusing because it isn't exactly all top-left to bottom-right diagonals.
It also expects you do to diagonals starting from the bottom left and going up that first column.
See the example provided and how it includes [9] and [5,5].
This is unclear and kinda bad. The point of the problem overall though is respecting the bounds of a matrix to avoid
attempting accessing out of bounds memory.

O(mn) time
O(1) space

***********************/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = matrix.size()-1; i >= 0; i--) {
            int x = i;
            int j = 0;
            int number = matrix[x][j];
            while (x < matrix.size() && j < matrix[0].size()) {
                if (matrix[x][j] != number) return false;
                x++; 
                j++;                
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            int i = 0;
            int y = j;
            int number = matrix[i][y];
            while (i < matrix.size() && y < matrix[0].size()) {
                if (matrix[i][y] != number) return false;
                i++; 
                y++;                
            }
        }
        
        return true;
    }
};