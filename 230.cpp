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
    void inorder(TreeNode* node, int& rem, int& result) {
        if (!node) return;
        
        inorder(node->left, rem, result);
        if (rem == 1) result = node->val;
        rem--;
        inorder(node->right, rem, result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }
};