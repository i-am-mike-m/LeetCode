/***********************

UGH what an obnoxious problem.

O(m + n) time where m and n are the sizes of the paragraph and the number of banned words
O(m) space where m is the number of banned words

***********************/

class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        for (int i = 0; i < p.size(); i++) {
            if (p[i] >= 'A' && p[i] < 'a') p[i] += ('a' - 'A');
        }
        unordered_set<string> b;
        unordered_map<string, int> count;
        unordered_set<char> bc ({'.', ' ', ',', '?', '!', ';', ':', '\'', '"'});
        int size = p.size();
        int num = 0;
        string result;
        
        for (auto each : banned) b.insert(each);
        
        for (int i = 0; i < size; i++) {
            if (bc.find(p[i]) != bc.end()) continue;
            int j = i+1;
            while (j < size && (bc.find(p[j]) == bc.end())) j++;
            string comp = p.substr(i, j-i);
            if (b.find(comp) == b.end()) count[comp]++;
            i = j;
        }
        
        for (auto each : count) {
            if (each.second > num) {
                num = each.second;
                result = each.first;
            }
        }
        
        return result;        
    }
};