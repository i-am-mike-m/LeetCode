/***********************

We use a vector to represent each morse code character where index 0 is 'a' and onward through the alphabet.
We construct a morse code word from each word in the set and insert it into an unordered_set.
Since multiple insertions of the same word do nothing, the size of the unordered_set is the number of unique morse code words.

O(*) time - This grows based on both the number of words and also the length of the words.
O(n) space

***********************/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alpha = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> form;
        
        for (auto each : words) {
            string build;
            for (auto letter : each) build += alpha[letter - 'a'];
            form.insert(build);
        }
        
        return form.size();
    }
};