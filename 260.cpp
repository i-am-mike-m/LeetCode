class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        vector<int> res {0, 0};
        // First Pass XOR
        for (auto each : nums) xors ^= each;
        // Get Rightmost Bit
        xors &= -xors;        
        // Final Pass
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & xors) == 0) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        
        return res;
    }
};