class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int minSeen = nums[0];
        int longest = 1;
        vector<int> lis (nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= minSeen) { minSeen = nums[i]; }
            else {                
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        lis[i] = max(lis[i], lis[j] + 1);
                        longest = max(longest, lis[i]);
                    }
                }
            }
        }
        return longest;        
    }
};