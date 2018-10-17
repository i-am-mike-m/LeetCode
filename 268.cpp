class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int targetSum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            targetSum += (i + 1);
            sum += nums[i];
        }
        
        return targetSum - sum;
    }
};