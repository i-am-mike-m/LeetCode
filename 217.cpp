/***********************

Too simple. Can also be done in O(nlgn) time with O(1) space.

O(n) time
O(n) space

***********************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto each : nums) {
            if (s.find(each) != s.end()) return true;
            else s.insert(each);
        }
        
        return false;
    }
};