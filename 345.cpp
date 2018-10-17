class Solution {
public:
    string reverseVowels(string s) {
        int front = 0;
        int back = s.size()-1;
        unordered_set<char> vowel {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        
        while (front < back) {
            while (vowel.find(s[front]) == vowel.end()) front++;
            while (vowel.find(s[back]) == vowel.end()) back--;
            
            if (front < back) {
                char temp = s[front];
                s[front] = s[back];
                s[back] = temp;
            }
            front++;
            back--;
        }
        
        return s;
    }
};