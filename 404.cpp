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
    int sumHelper(TreeNode* node, TreeNode* parent) {
        if (!node) return 0;
        int sum = 0;
        
        // This is a left leaf - return it's value.
        if (!node->left && !node->right && parent && (node == parent->left)) return node->val;
        else return sum + sumHelper(node->left, node) + sumHelper(node->right, node);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sumHelper(root, NULL);
    }
};