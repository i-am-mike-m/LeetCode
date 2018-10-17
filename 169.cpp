/***********************

The trick here is that since we are guaranteed there IS a majority element, it's count will always be greater
than all the other elements combined.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {        
        int element = nums[0];
        int count = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != element) {
                count--;
                if (count == 0) {
                    element = nums[i];
                    count = 1;
                }
            }
            else count++;
        }
        
        return element;
    }
};