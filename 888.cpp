class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> setA;
        vector<int> results;
        
        int sumA = 0;
        int sumB = 0;
        int diff;
        
        for (int i = 0; i < A.size(); i++) {
            setA.insert(A[i]);
            sumA += A[i];
        }
        for (int i = 0; i < B.size(); i++) {
            sumB += B[i];
        }
        
        diff = sumA - sumB;
        
        for (int i = 0; i < B.size(); i++) {
            int complement = B[i] + (0.5 * diff);
            auto search = setA.find(complement);
            
            if (search != setA.end()) {
                results.push_back(complement);
                results.push_back(B[i]);
                return results;
            }
        }
        
        return results;
    }
};