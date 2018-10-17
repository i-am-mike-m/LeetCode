class Solution {
public:
    string convertToTitle(int n) {
        string s;
        char next;
        while(n){
            n -= 1; 
            tmp = 'A' + n % 26;
            s = next + s;
            n /= 26;
        }

        return res;
    }
};