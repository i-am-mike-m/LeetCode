class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0] = 1;
        int sum = 0;
        int res = 0;
        
        for (auto each : A) {
            sum += each;
            res += prefixSumCount[sum - S];
            prefixSumCount[sum]++;            
        }
        
        return res;
    }
};