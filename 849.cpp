// O(n) time O(1) space
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // 300000 is arbitrary value > max array size of 20000 * 10.
        // This fixes the issue where one side does not start/end with a '1'
        int tensSinceOneSeen = 300000;
        // Forward Pass
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) tensSinceOneSeen = 0;
            else {
                tensSinceOneSeen += 10;
                seats[i] += tensSinceOneSeen;
            }
        }
        // Backward Pass
        tensSinceOneSeen = 300000;
        for (int i = seats.size()-1; i >= 0; i--) {
            if (seats[i] == 1) tensSinceOneSeen = 0;
            else {
                tensSinceOneSeen += 10;
                seats[i] = min(seats[i], tensSinceOneSeen);
            }
        }
        // Final Pass
        int maximum = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] != 1) maximum = max(maximum, seats[i]);
        }
        return maximum / 10;        
    }
};