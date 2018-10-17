class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN;
        int largestIndex = 0;
        int second = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (largest == INT_MIN) largest = nums[i];
            else if (nums[i] > largest) {                
                second = largest;
                largest = nums[i];                                
                largestIndex = i;
            }
            else if (nums[i] > second) second = nums[i];
        }
        return largest >= 2 * second ? largestIndex : -1;
    }
};