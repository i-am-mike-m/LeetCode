class Solution {
public:
    int sortAroundPivot (vector<int>& nums, int pivot, int start, int end) {        
        int val = nums[pivot];
        int smaller = start;
        int equal = start;
        int larger = end;
        
        while (equal <= larger) {
            if (nums[equal] < val) swap(nums[smaller++], nums[equal++]);
            else if (nums[equal] == val) equal++;
            else swap(nums[equal], nums[larger--]);
        }
        return equal - 1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int pivot = start + ((end - start) / 2);
        while(1) {
            pivot = sortAroundPivot(nums, pivot, start, end);
            if (nums.size() - pivot == k) return nums[pivot];
            else {
                if (nums.size() - pivot > k) {
                    start = pivot + 1;
                    pivot = start + ((end - start) / 2);
                }
                else {
                    end = pivot - 1;
                    pivot = start + ((end - start) / 2);
                }                
            }
        }
    }
};