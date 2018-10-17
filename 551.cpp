class Solution {
public:
    bool checkRecord(string s) {
        bool A = false;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                if (A) return false;
                else A = true;
            }
            if (s[i] == 'L' && i-2 >= 0 && s[i-1] == 'L' && s[i-2] == 'L') return false;            
        }
        return true;
    }
};