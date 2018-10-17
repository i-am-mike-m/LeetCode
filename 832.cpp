/***********************

This is fairly straightforward on reversing the rows.
To invert using abs(A[row][i] - 1) will take all 1's to 0's and all 0's to -1's, which become 1's.

O(n^2) time - assuming that n x n size is a requirment
O(n) space

***********************/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int row = 0; row < A.size(); row++) {
            for (int i = 0, j = A[row].size()-1; i < j; i++, j--) {
                int temp = A[row][i];
                A[row][i] = A[row][j];
                A[row][j] = temp;
            }
            
            for (int i = 0; i < A[row].size(); i++) {
                A[row][i] = abs(A[row][i] - 1);
            } 
        }
        
        return A;
    }
};