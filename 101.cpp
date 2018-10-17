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
    bool symHelper(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        
        if (left->val != right->val) return false;
        
        return symHelper(left->left, right->right) && symHelper(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symHelper(root->left, root->right);
    }
};