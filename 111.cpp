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
    int minDepth(TreeNode* node) {
        if (!node) return 0;
        else if (!node->left && !node->right) return 1;
        else if (node->left && node->right) return 1 + min(minDepth(node->left), minDepth(node->right));
        else if (node->left) return 1 + minDepth(node->left);
        else return 1 + minDepth(node->right);
    }
};