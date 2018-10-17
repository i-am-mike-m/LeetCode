class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        vector<int> results;
        
        for (auto each : nums1) n1[each]++;
        
        for (auto each : nums2) {
            if (n1.find(each) != n1.end()) {
                n1[each]--;
                if (n1[each] == 0) n1.erase(each);
                results.push_back(each);
            }
        }
        
        return results;
    }
};