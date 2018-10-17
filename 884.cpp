class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> words;
        vector<string> results;
        
        int indexA = 0;
        int sizeA = A.size();
        int indexB = 0;
        int sizeB = B.size();
        
        while (indexA < sizeA) {
            int start = indexA;
            int end, length;
            while (indexA < sizeA && A[indexA] != ' ') {                
                indexA++;                
            }
            
            end = indexA - 1;
            length = end - start + 1;
            
            string word = A.substr(start, length);
            words[word]++;
            
            indexA++;
        }
        while (indexB < sizeB) {
            int start = indexB;
            int end, length;
            while (indexB < sizeB && B[indexB] != ' ') {                
                indexB++;                
            }
            
            end = indexB - 1;
            length = end - start + 1;
                        
            string word = B.substr(start, length);
            words[word]++;
                        
            indexB++;
        }
        
        for (auto each : words) if (each.second == 1) results.push_back(each.first);
        
        return results;
    }
};