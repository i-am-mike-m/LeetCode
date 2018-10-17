class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int la = A.size();
        int lb = B.size();
        int n = 1;
        string s = "";
        while (la * n < lb) n++;
        for (int i = 0; i < n; i++) {
            s += A;
        }
        if (s.find(B) == std::string::npos) {
            s += A;
            n++;
            if (s.find(B) == std::string::npos) return -1;
            else return n;
        }
        else return n;        
    }
};