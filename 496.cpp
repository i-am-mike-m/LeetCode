/***********************

This one is kinda tricky, but is a good problem despite the number of downvotes.

NOTE: The array names in the description do not match those in the starter code. Need to adjust the starter code to use nums1 and
nums2 or make sure you keep things straight per the example is using the provided array names in the starter code.

O(n) time
O(n) space

***********************/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        vector<int> results(nums1.size(), 0);
        stack<int> current;
        
        for (int i = 0; i < nums2.size(); i++) {
            if (current.empty() || nums2[i] < current.top()) current.push(nums2[i]);
            else {
                while (!current.empty() && nums2[i] > current.top()) {
                    nge[current.top()] = nums2[i];
                    current.pop();
                }
                current.push(nums2[i]);
            }
        }
        while (!current.empty()) {
            nge[current.top()] = -1;
            current.pop();
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            results[i] = nge[nums1[i]];
        }
        
        return results;
    }
};