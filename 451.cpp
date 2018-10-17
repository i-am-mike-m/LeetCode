bool compare (pair<char,int> a, pair<char,int> b) {
    return a.second > b.second; 
}

class Solution {
public:
    string frequencySort(string s) {
        string ret (s.size(), ' ');
        vector<pair<int,int>> alphacount (256, make_pair(0,0));
        for (int i = 0; i < 256; i++) alphacount[i].first = i;
        for (int i = 0; i < s.size(); i++) {
            int alpha = s[i];
            alphacount[alpha].second++;
        }
        sort(alphacount.begin(), alphacount.end(), compare);
        
        int index = 0;
        for (int i = 0; i < alphacount.size(); i++) {
            if (alphacount[i].second > 0) {
                for (int j = 0; j < alphacount[i].second; j++) {
                    ret[index] = alphacount[i].first;
                    index++;
                }
            }
        }
        
        return ret;
    }
};