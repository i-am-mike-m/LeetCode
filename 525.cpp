class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> sumAtIndex;
        sumAtIndex[0] = -1;
        int sum = 0;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) if (nums[i] == 0) nums[i] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sumAtIndex.find(sum) != sumAtIndex.end()) {
                longest = max(longest, i - sumAtIndex[sum]);
            }
            else {
                sumAtIndex[sum] = i;
            }
        }
        return longest;        
    }
};