class Solution {
public:
    string replaceWords(vector<string>& dict, string S) {
        unordered_set<string> mp;
        for (auto each : dict) mp.insert(each);
        
        string res (S.size(), ' ');
        int readIndex = 0;
        int writeIndex = 0;
        
        int wordStartIndex = 0;
        while (readIndex < S.size()) {
            if (S[readIndex] == ' ') wordStartIndex = readIndex + 1;
            res[writeIndex] = S[readIndex];
            // If prefix is in the dictionary
            if (mp.find(S.substr(wordStartIndex, readIndex - wordStartIndex + 1)) != mp.end()) {
                while (readIndex < S.size() && S[readIndex] != ' ') readIndex++;
                readIndex--;                
            }
            readIndex++;
            writeIndex++;
        }
        return res.substr(0, writeIndex);        
    }
};