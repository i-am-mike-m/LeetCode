class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st;
        unordered_set<char> tbind;
        
        for (int i = 0; i < s.size(); i++) {
            auto iter = st.find(s[i]);
            if (iter == st.end()) {
                if (tbind.find(t[i]) != tbind.end()) return false;
                else {
                    st.insert({s[i], t[i]});
                    tbind.insert(t[i]);
                }                
            }
            else {
                if (iter->second != t[i]) return false;
            }
        }
        
        return true;
    }
};