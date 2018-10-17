class Solution {
public:
    bool valid (vector<vector<int>>& image, int x, int y) {
        if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size()) return true;
        else return false;
    }
    
    void fillHelper(vector<vector<int>>& image, int color, int newColor, int x, int y) {
        if (valid(image, x-1, y)) {
            if (image[x-1][y] == color) {
                image[x-1][y] = newColor;
                fillHelper(image, color, newColor, x-1, y);
            }
        }
        if (valid(image, x+1, y)) {
            if (image[x+1][y] == color) {
                image[x+1][y] = newColor;
                fillHelper(image, color, newColor, x+1, y);
            }
        }
        if (valid(image, x, y-1)) {
            if (image[x][y-1] == color) {
                image[x][y-1] = newColor;
                fillHelper(image, color, newColor, x, y-1);
            }
        }
        if (valid(image, x, y+1)) {
            if (image[x][y+1] == color) {
                image[x][y+1] = newColor;
                fillHelper(image, color, newColor, x, y+1);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        if (color == newColor) return image;
        
        fillHelper(image, color, newColor, sr, sc);
        
        return image;        
    }
};