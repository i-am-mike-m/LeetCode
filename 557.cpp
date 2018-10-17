/***********************

find() is used to locate the next occurrence of a space " ". When find() has a value of string::npos it means the end of the string
has been encountered. We use std::reverse to reverse substring from a starting value to the character before the space. This must be
done once more outside the loop for the final word.

O(n) time
O(1) space

***********************/

class Solution {
public:
    string reverseWords(string s) {        
        int start = 0;
        size_t found = s.find(" ", start);
        while (found != string::npos) {
            int end = found;
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            found = s.find(" ", start);
        }
        
        reverse(s.begin() + start, s.end());
        
        return s;
    }
};