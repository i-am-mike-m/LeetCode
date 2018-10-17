class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int readIndex = 0;
        int writeIndex = 0;        
        
        for (/*readIndex*/; readIndex < nums.size(); readIndex++) {
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;                
            }            
        }
        
        return writeIndex;
    }
};