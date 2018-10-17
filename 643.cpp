class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double maxAvg = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];            
        }        
        maxAvg = sum / k;
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            maxAvg = max(maxAvg, sum / k);            
        }
        
        return maxAvg;
    }
};