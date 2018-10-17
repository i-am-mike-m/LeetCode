/***********************

This technique of read/write index is used for many array traversal problems.

O(n) time
O(1) space

***********************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        int writeIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroCount++;
            else {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        while (zeroCount) {
            nums[writeIndex] = 0;
            writeIndex++;
            zeroCount--;
        }
        
        return;
    }
};