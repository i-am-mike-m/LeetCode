/***********************

So many combinations of cases. Easy to get mixed up and miss something.

O(n) time
O(1) space

***********************/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int wordCapCount = 0;
        int wordLowCount = 0;
        
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ' ') {            
                wordCapCount = 0;
                wordLowCount = 0;
            }
            
            // First Char in Word
            if (wordCapCount == 0 && wordLowCount == 0) {
                // Starts Lower
                if (word[i] >= 'a') {
                    // Word must be all lowercase.
                    while (i < word.size() && word[i] != ' ') {
                        if (word[i] < 'a') return false;
                        i++;
                    }
                }                
                // Starts Upper
                else if (word[i] < 'a') {                                        
                    while (i < word.size() && word[i] != ' ') {
                        if (word[i] < 'a' && wordLowCount > 0) return false;                        
                        else if (word[i] < 'a') wordCapCount++;
                        else if (word[i] >= 'a' && wordCapCount > 1) return false;
                        else wordLowCount ++;
                        
                        i++;
                    }
                }
            }
        }
        
        return true;
    }    
};