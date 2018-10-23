class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cache (10001, 0);
        for (int i = 0; i < nums.size(); i++) {
            cache[nums[i]] += nums[i];
        }
        int first = cache[1];
        int second = 0;
        for (int i = 2; i < 10001; i++) {            
            if (i % 2 == 0) {
                second = max(second + cache[i], first);                
            }
            else {
                first = max(first + cache[i], second);
            }
        }
        return max(first, second);
    }
};