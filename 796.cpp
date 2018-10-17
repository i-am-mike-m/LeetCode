/***********************

To get this to O(n) time requires a linear substring search. Watch out for the edge case where A / B are different sizes.

O(n) time
O(n) space

***********************/

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        string cat = B + B;
        
        // This can be improved with a linear substring search        
        if (cat.find(A) != std::string::npos) return true;
        else return false;
    }
};