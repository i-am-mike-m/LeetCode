class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> candidates;
        unordered_map<int,int> freq;
        int maxf = 0;
        int maxSubArrayLength = nums.size();
        
        for (auto each : nums) freq[each]++;
        for (auto each : freq) {
            if (each.second > maxf) {
                candidates.clear();
                candidates.push_back(each.first);                
            }
            else if (each.second == maxf) candidates.push_back(each.first);
            maxf = max(maxf, each.second);
        }
        
        for (auto each : candidates) {
            int i = 0;
            int start, end;
            int count = 0;
            
            while (nums[i] != each) i++;
            start = i;
            
            for (i; i < nums.size() && count < maxf; i++) {
                if (nums[i] == each) count++;
            }
            end = i-1;
            int length = end - start + 1;
            maxSubArrayLength = min(maxSubArrayLength, length);
        }
        
        return maxSubArrayLength;        
    }
};