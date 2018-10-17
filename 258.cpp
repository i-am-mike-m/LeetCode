/***********************

Not exactly sure about the time/space. The problem grows somewhat with the number of digits in 'num', but not linearly...

O(1) time
O(1) space

***********************/

class Solution {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            string convert = to_string(num);
            int sum = 0;
            
            for (auto each : convert) {
                sum += int(each - 48);
            }
            num = sum;            
        }
        
        return num;
    }
};