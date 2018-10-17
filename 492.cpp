class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> results(2,0);
        int w = sqrt(area);
        
        while (area % w != 0) {
            w--;
        }
        
        results[0] = (area / w);
        results[1] = w;
        
        return results;
    }
};