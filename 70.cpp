class Solution {
public:   
    int climbStairs(int n) {        
        int backOne = 1;
        int backTwo = 0;
        for (int i = 1; i <= n; i++) {
            int temp = backOne + backTwo;
            backTwo = backOne;
            backOne = temp;
        }
        
        return backOne;
    }
};