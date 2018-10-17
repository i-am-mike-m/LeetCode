class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int runLength = 1;
        int index = 0;
        int maxRun = 1;
        
        while (index + 1 < nums.size()) {
            if (nums[index + 1] > nums[index]) runLength++;
            else {
                maxRun = max(maxRun, runLength);
                runLength = 1;
            }
            index++;
        }
        maxRun = max(maxRun, runLength);
        return maxRun;
    }
};