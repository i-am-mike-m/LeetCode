/***********************

This is a pretty good problem that demonstrates the power of the '/' and '%' combination for indexing 2D matrices.
Watch out for the rule that if the indicated new size isn't valid then you must return the original matrix.

O(mn) time
O(mn) space

***********************/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size()) return nums;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
               
        int count = 0;
        int rowsize = matrix[0].size();
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                matrix[count/rowsize][count%rowsize] = nums[i][j];
                count++;
            }
        }
        
        return matrix;
    }
};