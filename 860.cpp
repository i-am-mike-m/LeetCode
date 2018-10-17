/***********************

This is a trivial problem. Just remember that you can use tens as change...

O(n) time
O(1) space

***********************/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) fives++;
            else if (bills[i] == 10) {
                fives--;                
                tens++;
            }
            else {
                if (tens > 0) {
                    tens--;
                    fives--;
                }
                else fives -=3;
            }
            if (fives < 0) return false;
        }
        return true;
    }
};