class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        vector<string> results (nums.size(), "");
        int count = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
        }
        
        while (!pq.empty()) {
            pair<int,int> current = pq.top();
            pq.pop();
            
            if (count == 1) results[current.second] = "Gold Medal";
            else if (count == 2) results[current.second] = "Silver Medal";
            else if (count == 3) results[current.second] = "Bronze Medal";
            else results[current.second] = to_string(count);
            
            count++;
        }
        
        return results;
    }
};