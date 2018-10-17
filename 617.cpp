/***********************

This is a very good problem. Be sure to check for the standard tree pitfalls such as NULL nodes and avoiding attempting to access
a ->left, ->right or ->val of a NULL node.

O(n + m) time - we are touching each node in both trees once, so the size of the larger tree drives the growth
O(n + m) space

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
    TreeNode* mergeHelper(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        TreeNode* node = new TreeNode(0);
        
        if (t1) node->val += t1->val;
        if (t2) node->val += t2->val;
        
        if (!t1) {
            node->left = t2->left;
            node->right = t2->right;
        }
        else if (!t2) {
            node->left = t1->left;
            node->right = t1->right;
        }
        else {
            node->left = mergeHelper(t1->left, t2->left);
            node->right = mergeHelper(t1->right, t2->right);
        }
        
        return node;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        if (!t1) return t2;
        if (!t2) return t1;
        
        TreeNode* root = mergeHelper(t1, t2);
        return root;
    }
};