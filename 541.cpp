class Solution {
public:
    string reverseStr(string s, int k) {
        int index = 0;
        int size = s.size();
        
        while (index < size) {
            int start = index;
            if (start + k > size) reverse(s.begin() + start, s.end());
            else reverse(s.begin() + start, s.begin() + start + k);
            index += 2 * k;
        }
        
        return s;
    }
};