class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = start + ((end - start) / 2);
            if (nums[start] > nums[end]) {
                // Reset is in upper half
                if (nums[mid] > nums[end]) {
                    start = mid + 1;                
                }
                // Reset is in lower half
                else if (nums[start] > nums[mid]) {
                    end = mid;
                }
            }
            else return nums[start];            
        }
        return nums[start];
    }
};