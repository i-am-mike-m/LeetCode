class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        
        
        for (int i = 0; i < emails.size(); i++) {            
            string build;
            int index = 0;
            for (int j = 0; j < emails[i].size(); /**/) {
                build = emails[i];                
                index = 0;
                while (emails[i][j] != '@') {
                    if (emails[i][j] != '+' && emails[i][j] != '.') {
                        build[index] = emails[i][j];
                        index++;
                    }
                    if (emails[i][j] == '+') {
                        while (emails[i][j+1] != '@') j++;                        
                    }
                    j++;
                }
                for (/**/; j < emails[i].size(); j++) {
                    build[index] = emails[i][j];
                    index++;
                }
                set.insert(build.substr(0, index));
            }            
        }
        return set.size();
    }
};