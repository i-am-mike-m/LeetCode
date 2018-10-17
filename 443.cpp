class Solution {
public:
    int compress(vector<char>& chars) {
        int readIndex = 0;
        int writeIndex = 0;
        while (readIndex < chars.size()) {            
            char current = chars[readIndex];
            readIndex++;
            int count = 1;
            
            while (readIndex < chars.size() && (chars[readIndex] == current)) {
                count++;
                readIndex++;
            }
            
            chars[writeIndex] = current;
            writeIndex++;
            
            if (count > 1) {
                string s = to_string(count);            
                for (int i = 0; i < s.size(); i++) {
                    chars[writeIndex] = s[i];
                    writeIndex++;
                }
            }
        }
        
        return writeIndex;
    }
};