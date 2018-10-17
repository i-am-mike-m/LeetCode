class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mapAB;        
        int res = 0;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                mapAB[A[i] + B[j]]++;
            }
        }
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                auto iter = (mapAB.find(0 - C[i] - D[j]));
                if (iter != mapAB.end()) {
                   res += iter->second;
                }
            }
        }
        
        return res;
    }
};