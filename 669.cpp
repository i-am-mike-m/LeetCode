/***********************

This is a great problem. Due to BST rules, if the current node is lower than the left bound we must check the right subtree for a
candidate replacement that is above the left bound. If none exists, this entire branch is truncated as NULL. The same is true for the
right bound. If the current node is within the bounds, it's left and right children must be recursively checked for validity and
updated as required.

O(n) time
O(h) space - due to call stack and recursion

***********************/

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
    TreeNode* trimHelper(TreeNode* node, int L, int R) {
        if (!node) return NULL;
        
        if (node->val < L) return trimHelper(node->right, L, R);
        else if (node->val > R) return trimHelper(node->left, L, R);
        else {
            node->left = trimHelper(node->left, L, R);
            node->right = trimHelper(node->right, L, R);            
        }
        
        return node;
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        
        TreeNode* newRoot = trimHelper(root, L, R);
        
        return newRoot;
    }
};