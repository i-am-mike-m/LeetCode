class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {        
        int size = A.size();
        
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == 0) A[i][0] += min(A[i-1][0], A[i-1][j+1]);
                else if (j == size - 1) A[i][j] += min(A[i-1][size-1], A[i-1][size-2] );
                else A[i][j] += min( {A[i-1][j-1], A[i-1][j], A[i-1][j+1]} );                    
            }
        }
        
        int res = INT_MAX;
        for (auto each : A[size-1]) res = min(res, each);
        
        return res;
    }
};