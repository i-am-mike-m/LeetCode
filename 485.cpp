/***********************

Careful to make sure you do one last check for maxCount after leaving the for-loop. This is because we check to update maxCount
when we encounter a 0, so if the final number is a 1 you may need to update maxCount one more time.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) count++;
            else {
                maxCount = max(count, maxCount);
                count =0;
            }
        }
        
        maxCount = max(count, maxCount);
        return maxCount;
    }
};