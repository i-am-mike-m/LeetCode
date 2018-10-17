class Solution {
public:
    static bool compare (int i,int j) { return (i > j); }
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), compare);
        sort(s.begin(), s.end(), compare);
               
        int g_size = g.size();
        int s_size = s.size();
        int min_size = min(g_size, s_size);
        int count = 0;
        int g_index = 0;
        int s_index = 0;
        
        while (g_index < g_size && s_index < s_size) {
            if (s[s_index] >= g[g_index]) {
                count++;   
                s_index++;
            }
            g_index++;
        }
        
        return count;        
    }
};