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
    void preorderHelper(Node* node, vector<int>& results) {
        if (!node) return;
        
        results.push_back(node->val);
        
        for (int i = 0; i < node->children.size(); i++) {
            preorderHelper(node->children[i], results);
        }
        
        return;
    }
    
    vector<int> preorder(Node* root) {
        vector<int> results;
        
        preorderHelper(root, results);
        
        return results;
    }
};