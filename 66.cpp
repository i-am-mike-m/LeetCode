class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size()-1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry) {
                carry--;
                digits[i]++;                
            }
            if (digits[i] == 10) {
                digits[i] = 0;
                carry++;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        
        return digits;
    }
};