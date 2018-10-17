/***********************

This is a bad problem. It is literally finding the max in an array.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int index = 0;
        int max = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > max) {
                max = A[i];
                index = i;
            }
        }
        return index;
    }
};