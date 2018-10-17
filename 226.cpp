/***********************

Max Howell tweet:

"Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off."

O(n) time
O(h) space - h is the height of the tree due to recursive stack

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
    void invertHelper(TreeNode* node) {
        if (!node) return;
        
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        if (node->left) invertHelper(node->left);
        if (node->right) invertHelper(node->right);        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invertHelper(root);
        
        return root;
    }
};