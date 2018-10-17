class Solution {
public:
    void addGroup(vector<vector<int>>& results, int start, int end) {
        vector<int> add(2,0);
        add[0] = start;
        add[1] = end;
        results.push_back(add);
    }
    
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> results;
        int size = S.size();
        
        for (int i = 0; i < size; /* N/A */) {                      
            int end = i;
            int count = 0;
            
            do {
                end++;
                count++;
            } while (end < size && S[end] == S[end-1]);
            
            if (count >= 3) addGroup(results, i, end-1);
            i = end;
            
        }
        
        return results;
    }
};