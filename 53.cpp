class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSeen = nums[0];
        int running = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxSeen) {
                maxSeen = max(nums[i], running + nums[i]);
                running = maxSeen;
            }
            else {
                running = max(running + nums[i], nums[i]);
                maxSeen = max(maxSeen, running);
            }
        }
        
        return maxSeen;
    }
};