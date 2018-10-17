class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0) return 0;        
        bool charSeen = s[0] == ' ' ? false : true;
        int count = charSeen ? 1 : 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && charSeen) {
                charSeen = false;                
            }
            if (s[i] != ' ') {
                if (!charSeen) {
                    charSeen = true;
                    count++;
                }   
            }
        }
        
        return count;        
    }
};