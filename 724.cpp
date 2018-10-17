class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int rightSum = 0;
        int leftSum = 0;
        for (int i = 1; i < nums.size(); i++) rightSum += nums[i];
        if (rightSum == 0) return 0;
        for (int i = 1; i < nums.size(); i++) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};