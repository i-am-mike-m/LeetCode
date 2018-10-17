class Solution {
public:
    bool validHelper(string& s, bool del, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                if (!del) return validHelper(s, true, start + 1, end) || validHelper(s, true, start, end - 1);
                else return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {        
        return validHelper(s, false, 0, s.size()-1);
    }
};