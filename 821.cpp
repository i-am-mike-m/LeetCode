/***********************

Start with a results array initialized to 0. Find all locations of the target letter and store in an array/vector.
There are three 'phases' to this problem. Indices before any target location, indices between two target locations and
indices after all target locations. Use a variable to track where the next target location is and update this as your 'i'
passes that location. When between two target locations (the location index isn't 0 and 'i' isn't past the final location)
you must determine which location is the closest.

O(n) time
O(n) space

***********************/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> C_locations;
        vector<int> results(S.size(), 0);
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) C_locations.push_back(i);
        }
        
        int C_index = 0;
        for (int i = 0; i < S.size(); i++) {
            if (i < C_locations[C_index]) {
                if (C_index == 0) {
                    results[i] = C_locations[C_index] - i;
                }
                else {
                    results[i] = min(C_locations[C_index] - i, i - C_locations[C_index - 1]);
                }
            }
            else if (C_index < C_locations.size() - 1) C_index++;
            else results[i] = i - C_locations[C_index];
        }
        
        return results;
    }
};