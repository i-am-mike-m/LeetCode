class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        unordered_set<char> seen;
        bool seenTwo = false;
        pair<char,char> firstWrong = { ' ', ' ' };
        pair<char,char> secondWrong = { ' ', ' ' };
        
        for (int i = 0; i < min(A.size(), B.size()); i++) {
            if (seen.find(A[i]) != seen.end()) seenTwo = true;
            seen.insert(A[i]);
            if (A[i] != B[i]) {
                if (firstWrong.first == ' ') {
                    firstWrong.first = A[i];
                    firstWrong.second = B[i];
                }
                else if (secondWrong.first == ' ') {
                    secondWrong.first = A[i];
                    secondWrong.second = B[i];
                }
                else return false; 
            }
        }
        if (firstWrong.first == ' ') return seenTwo;
        else return firstWrong.first == secondWrong.second && firstWrong.second == secondWrong.first;        
    }
};