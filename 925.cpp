class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.size() < name.size()) return false;
        int ni = 0;
        int ti = 0;
        while (ni < name.size()) {
            if (name[ni] == typed[ti]) { ni++; ti++; }
            else if (ti > 0 & (typed[ti] == typed[ti - 1])) ti++;
            else return false;
        }
        return true;
    }
};