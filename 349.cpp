class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;        
        vector<int> results;
        
        for (auto each : nums1) {
            n1.insert(each);
        }
        
        for (auto each : nums2) {
            if (n1.find(each) != n1.end()) {
                results.push_back(each);
                n1.erase(each);
            }
            
        }
        
        return results;
    }
};