class Solution {
public:
    int palinHelper(string& s) {        
        int count = 0;
        int size = s.size();
        
        for (int start = 0; start < s.size(); start++) {
            int front = start;
            int back = start;
            while (front >= 0 && back < size && s[front] == s[back]) {               
                count++;
                front--;
                back++;
            }
            
            front = start - 1;
            back = start;            
            while (front >= 0 && back < size && s[front] == s[back]) {
                count++;
                front--;
                back++;
            }
        }
        
        return count;
    }
    
    int countSubstrings(string s) {                
        return palinHelper(s);
    }
};