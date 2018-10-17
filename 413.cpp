class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int count = 0;        
        
        for (int i = 2; i < A.size(); i++) {
            int grow = 1;
            int diff = A[i] - A[i - 1];
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
                count += grow;
                grow++;
                
                while ((i + 1 < A.size()) && (A[i + 1] - A[i] == diff)) {
                    count += (grow);
                    grow++;
                    i++;
                }            
            }                            
        }
        
        return count;
    }
};