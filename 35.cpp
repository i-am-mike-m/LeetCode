class Solution {
public:
    int searchHelp(vector<int>& nums, int target, int front, int back) {
        if (front > back) return front;
        
        int mid = front + ((back - front) / 2);
        
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return searchHelp(nums, target, mid + 1, back);
        else return searchHelp(nums, target, front, mid - 1);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return searchHelp(nums, target, 0, nums.size()-1);
    }
};