/***********************

It's a  math problem. Thumbs down.


***********************/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int mn = nums[0];
        for (int n : nums) mn = min(mn, n);
        int res = 0;
        for (int n : nums) res += n - mn;
        return res;
    }
};