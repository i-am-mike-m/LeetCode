/***********************

Excellent tree problem!

O(n) time
O(1) space

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
    void reverseInorderAdd(TreeNode* node, int& sum) {
        if (!node) return;
        
        reverseInorderAdd(node->right, sum);        
        int val = node->val;
        node->val += sum;
        sum += val;
        reverseInorderAdd(node->left, sum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        int sum = 0;
        reverseInorderAdd(root, sum);
        
        return root;
    }
};