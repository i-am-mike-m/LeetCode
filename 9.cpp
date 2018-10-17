class Solution {
public:
    bool isPalindrome(string x) {
        int front = 0;
        int back = x.size()-1;
        while (front < back) {
            if (x[front] != x[back]) return false;
            front++; back--;
        }
        return true;
    }
    
    bool isPalindrome(int x) {
        string word = to_string(x);
        return isPalindrome(word);
    }
};