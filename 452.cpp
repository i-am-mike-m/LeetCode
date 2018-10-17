bool compare (pair<int,int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

class Solution {
public:      
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() == 0) return 0;        
        sort(points.begin(), points.end(), compare);        
        int arrows = 1;
        int index = 0;
        int last_hit = points[index].second;
                        
        while (index < points.size()) {
            // All these indices are hit by current arrow.
            while (index < points.size() - 1 && last_hit >= points[index + 1].first) { index++; }            
            // Need more arrows if haven't hit all indices.
            index++;
            if (index < points.size()) {
                last_hit = points[index].second;
                arrows++;
            }
        }
        return arrows;
    }
};