/***********************

This is essentially a very easy greedy algorithm and as such begins with a sort (nlgn time).
Since the number of elements is guaranteed to be even you are just taking the minimum number out of each of the sorted pairs.
The problem description, if not fixed, is also incorrect and indicates you're getting the maximum when really it's the minimum.

O(nlgn) time
O(1) space

***********************/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for (int i = 0; i <= nums.size() - 2; i += 2) {
            sum += min(nums[i], nums[i+1]);
        }
        
        return sum;
    }
};