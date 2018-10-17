/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> results;
        int level = 0;
        if (!root) return results;
        results.push_back(vector<int>(0,0));
                
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
            
        // If only 1 value in queue it is the NULL and is the end.
        while(q.size() > 1) {            
            // NULL is flag for end of level.
            while (q.front() != NULL) {
                Node* current = q.front();
                q.pop();
                
                results[level].push_back(current->val);
                for (auto each : current->children) {
                    if (each != NULL) q.push(each);
                }
            }
            // Proceed to next level.
            q.pop();
            q.push(NULL);
            level++;
            if (q.size() > 1) results.push_back(vector<int>(0,0));
        }
        
        return results;
    }
};