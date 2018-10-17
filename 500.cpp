/***********************

Creating sets of characters to represent the keyboard row requires O(1) space because it is a constant number of elements.
Checking whether a specific character from a word is in the set is an O(1) operation.
Checking whether a word is in any given set (keyboard row) is an O(n) operation where 'n' is the length of the string.

O(n) time
O(1) space

***********************/

class Solution {
public:
    bool isValid(string word, unordered_set<char>& set) {
        for (auto each : word) {
            if (set.find(each) == set.end()) return false;
        }
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> one = {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'};
        unordered_set<char> two = {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'};
        unordered_set<char> three = {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'};
        vector<string> results;
               
        for (int i = 0; i < words.size(); i++) {
            if (isValid(words[i], one)) results.push_back(words[i]);
            else if (isValid(words[i], two)) results.push_back(words[i]);
            else if (isValid(words[i], three)) results.push_back(words[i]);
        }
        
        return results;
    }
};