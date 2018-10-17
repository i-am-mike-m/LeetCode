/***********************

This problem is far too wordy for it's actual complexity. The function stoi() is great for taking a string to an integer. I track
all of the old valid rounds in a vector in case multiple operations come in a row that invalidate old rounds.

O(n) time
O(n) space

***********************/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> valid;
        int points = 0;
        
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                points -= valid[valid.size()-1];
                valid.pop_back();
            }
            else if (ops[i] == "D") {
                int round = 2 * valid[valid.size()-1];
                points += round;
                valid.push_back(round);                
            }
            else if (ops[i] == "+") {
                int round = valid[valid.size()-1] + valid[valid.size()-2];
                points += round;
                valid.push_back(round);
            }
            else {
                int round = stoi(ops[i]);
                points += round;
                valid.push_back(round);
            }
        }
        
        return points;
    }
};