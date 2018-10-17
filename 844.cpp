class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        
        for (auto each : S) {
            if (each == '#' && !s.empty()) s.pop();
            else if (each != '#') s.push(each);
        }
        for (auto each : T) {
            if (each == '#' && !t.empty()) t.pop();
            else if (each != '#') t.push(each);
        }
        
        while (!s.empty() && !t.empty()) {            
            if (s.top() != t.top()) return false;
            s.pop();
            t.pop();
        }
        return s.empty() && t.empty();
    }
};