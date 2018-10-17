class Solution {
public:
    bool checkHelper(vector<int>& nums, int start, bool changed, int prevMax) {
        for (int i = start; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) {
                if (changed) return false;
                else {
                    if (i == 0) changed = true;                    
                    else {
                        int temp = nums[i];
                        nums[i] = prevMax;
                        bool changeBefore = checkHelper(nums, i, true, prevMax);
                        if (changeBefore) return true;
                        nums[i] = temp;
                        nums[i+1] = nums[i];
                        bool changeAfter = checkHelper(nums, i + 1, true, prevMax);
                        return changeBefore || changeAfter;
                    }
                }
            }
            prevMax = nums[i];
        }
        return true;
    }
    
    bool checkPossibility(vector<int>& nums) {        
        if (nums.size() == 0) return true;
        return checkHelper(nums, 0, false, nums[0]);
    }
};