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
    int diaHelper(TreeNode* node, int& maxDia) {
        if (!node) return 0;
        
        int depthBelowLeft = diaHelper(node->left, maxDia);
        int depthBelowRight = diaHelper(node->right, maxDia);
        
        maxDia = max(maxDia, depthBelowLeft + depthBelowRight);
        
        return 1 + max(depthBelowLeft, depthBelowRight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        
        diaHelper(root, maxDia);
        
        return maxDia;
    }
};