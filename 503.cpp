class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> s;
        vector<int> res (nums.size(), -1);
        
        for (int i = 0; i < 2 * nums.size(); i++) {
            int j = i % nums.size();
            while (!s.empty() && s.top().first < nums[j]) {
                res[s.top().second] = nums[j];
                s.pop();
            }
            if (i < nums.size()) s.push(make_pair(nums[j], j));
        }
        
        return res;
    }
};