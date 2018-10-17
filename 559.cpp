/*
// Definition for a Node.
class Node {
public:
    int val;
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
    void depthHelper(Node* node, int& maxDepth, int currentDepth) {
        if (!node) return;
        
        if (currentDepth > maxDepth) maxDepth = currentDepth;
        for (auto each : node->children) {
            depthHelper(each, maxDepth, currentDepth + 1);
        }
    }
    
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int maxDepth = 1;
        depthHelper(root, maxDepth, 1);
        
        return maxDepth;
    }
};