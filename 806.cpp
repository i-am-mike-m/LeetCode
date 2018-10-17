/***********************

I thought the wording of this question was slightly confusing. The width array tells you the "width" used by each character of the
alphabet. Ensure you always stop filling a line at or before 100 width. Whenever you would go over 100 you increment the number of
lines required. Then just use the current width when done with the word as the second index in the results - the "remainder".

O(n) time
O(1) space

***********************/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> results = {0, 0};
        if (S == "") return results;
        int lines = 1;
        int length = 0;        
        
        
        for (int i = 0; i < S.size(); i++) {
            int width = widths[S[i] - 'a'];
            if (length + width > 100) {
                length = width;
                lines++;
            }
            else length += width;
        }
        results[0] = lines;
        results[1] = length;
        
        return results;
    }
};