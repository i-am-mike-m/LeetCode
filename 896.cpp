class Solution {
public:
    bool isMonotonic(vector<int>& A) {        
        int index = 0;
        while (index + 1 < A.size() && A[index] == A[index+1]) index++;
        
        if (index + 1 < A.size() && A[index] < A[index+1]) {
            for (int i = index; i < A.size() - 1; i++) {
                if (A[i+1] < A[i]) return false;
            }
        }
        else {
            for (int i = index; i < A.size() - 1; i++) {
                if (A[i+1] > A[i]) return false;
            }
        }
        return true;
    }
};