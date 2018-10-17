/***********************

Don't mind all the downvotes on this problem. They were from before they clarified the problem statement.
It's a good problem.

O(n) time
O(1) space

***********************/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val ( {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}} );
        int count = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if ((i + 1 < size) && (val[s[i+1]] > val[s[i]])) {                
                count = count + val[s[i+1]] - val[s[i]];
                i++;
            }
            else count += val[s[i]];
        }        
        
        return count;
    }
};