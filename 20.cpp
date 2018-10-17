class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        unordered_map<char, char> p { {'(',')'}, {'[', ']'}, {'{', '}'} };
        
        for (int i = 0; i < s.size(); i++) {
            if (p.find(s[i]) != p.end()) t.push(s[i]);
            else {
                if (t.empty() || (s[i] != p.find(t.top())->second)) return false;
                else t.pop();
            }
        }
        return t.empty();
    }
};