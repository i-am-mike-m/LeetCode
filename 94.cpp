/***********************

The inorder traversal is a classic tree traversal meaning visit left subtree, visit node, visit right subtree.

O(n) time
O(h) space where h is the height of the tree due to recursion

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
    void inorder(TreeNode* node, vector<int>& results) {
        if (!node) return;
        
        inorder(node->left, results);
        results.push_back(node->val);
        inorder(node->right, results);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        inorder(root, results);
        
        return results;
    }
};