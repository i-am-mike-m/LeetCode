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
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == p || node == q) return node;
        if (!node) return NULL;
        
        TreeNode* left = lowestCommonAncestor(node->left, p, q);
        TreeNode* right = lowestCommonAncestor(node->right, p, q);
        
        if (left != NULL && right != NULL) return node;
        else return left != NULL ? left : right;        
    }
};