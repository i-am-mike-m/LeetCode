class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return  nums.size();
        int write = 0;        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[write]) {
                write++;
                nums[write] = nums[i];
            }
        }
        return write + 1;
    }
};