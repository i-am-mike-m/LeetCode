class compare
    {
    // This is a custom comparator for the complex priority_queue object.
    // Only need to compare the first of each pair since that's the matrix value.
    public:
        bool operator() (pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
        {
            return a.first > b.first;
        }
    };

class Solution {
public:      
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Pair consists of first: matrix value - second: nested pair representing row/column where value is found.
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pq;
        int count = 1;
        
        for (int i = 0; i < matrix.size(); i++) {
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        
        while (count < k) {
            int row = pq.top().second.first;
            int next_index = pq.top().second.second + 1;
            pq.pop();
            if (next_index < matrix[0].size()) pq.push(make_pair(matrix[row][next_index], make_pair(row, next_index)));
            count++;
        }
                
        return pq.top().first;
    }
};