class Solution {
public:
    bool isPowerOfTwo(int n) {        
        int test = 1;
        for (int i = 0; i < 31; i++) {
            if ((n ^ test) == 0) return true;
            test <<= 1;
        }
        
        return false;
    }
};