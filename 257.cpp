/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pathHelper(TreeNode* node, vector<string>& results, string current) {        
        current += to_string(node->val);
        if (node->left) pathHelper(node->left, results, current + "->");
        if (node->right) pathHelper(node->right, results, current + "->");
        
        if (!node->left && !node->right) results.push_back(current);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        string current = "";
        if (!root) return results;        
        pathHelper(root, results, current);
        return results;       
    }
};