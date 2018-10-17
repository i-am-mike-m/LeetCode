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
    TreeNode* pruneHelper(TreeNode* node) {
        if (!node) return node;        
        
        node->left = pruneHelper(node->left);
        node->right = pruneHelper(node->right);
        
        if (!node->left && !node->right) return node->val == 1 ? node : NULL;
        return node;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        root->left = pruneHelper(root->left);
        root->right = pruneHelper(root->right);
        
        return root;
    }
};