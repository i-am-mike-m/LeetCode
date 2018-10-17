/***********************

This is a very simple form of a technique known as backtracking. The time complexity ends up being 2^n because there are two
possible alternative versions for each character. The space complexity is O(n) because the depth of the call stack is based on the 
length of the provided string. Good problem!

O(2^n) time
O(n) space

***********************/

class Solution {
public:
    string invertCase(string S, int count) {
        if (S[count] >= 'a') S[count] -= ('a' - 'A');
        else S[count] += ('a' - 'A');
        
        return S;
    }
    
    void perm(vector<string>& result, string S, int count) {
        if (count >= S.size()) {
            result.push_back(S);
            return;
        }
        
        if (isalpha(S[count])) {            
            perm(result, invertCase(S, count), count + 1);            
            perm(result, S, count + 1);            
        }
        else perm(result, S, count + 1);
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        perm(result, S, 0);
        
        return result;
    }
};