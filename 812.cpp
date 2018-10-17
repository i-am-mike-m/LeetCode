/***********************

This is a bad problem. The solution is brute force combined with a math equation that is realistically just gonna be found
using Google or reading someone else's problem solution.

O(n^3) time
O(1) space

***********************/

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (auto &i : points)
            for (auto &j : points)
                for (auto &k : points)
                    res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};