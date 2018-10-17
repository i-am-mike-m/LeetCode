class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {        
        int start = 0;
        int end = nums.size()-1;
                
        while (start <= end) {
            if (start == end) return nums[start];
            int mid = start + ((end - start)/2);
            
            if (mid % 2 == 1) {
                if (nums[mid] == nums[mid - 1]) start = mid + 1;                
                else end = mid - 1;
            }
            else {
                if (nums[mid] == nums[mid + 1]) start = mid + 2;
                else end = mid - 2;
            }            
        }
    }
};