class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || k == nums.size() || nums.size() <= 1) return;
        int count = 0;
        int start = 0;
        int size = nums.size();
        
        for (int i = 0; count < size && i < size; i = start + 1) {
            start = i;
            int next = (i + k) % size;
            int next_num;
            int current_num = nums[i];            
            while (next != start) {
                next = (i + k) % size;
                next_num = nums[next];
                nums[next] = current_num;
                current_num = next_num;
                i += k;
                count++;
            }            
        }
        return;
    }
};