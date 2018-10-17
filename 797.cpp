class Solution {
public:
    void pathHelper(vector<vector<int>>& graph, int location, vector<int>& path, vector<vector<int>>& paths) {
        if (location == graph.size()-1) {
            paths.push_back(path);
            return;
        }
        else {
            for (int i = 0; i < graph[location].size(); i++) {
                path.push_back(graph[location][i]);
                pathHelper(graph, graph[location][i], path, paths);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int location = 0;
        vector<int> path { 0 };
        vector<vector<int>> paths;
        pathHelper(graph, 0, path, paths);
        
        return paths;
    }
};