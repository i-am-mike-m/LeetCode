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
    int tiltHelper(TreeNode* node, int& treeTilt) {
        if (!node) return 0;
        
        int sumBelowLeft = tiltHelper(node->left, treeTilt);
        int sumBelowRight = tiltHelper(node->right, treeTilt);
        
        treeTilt += abs(sumBelowRight - sumBelowLeft);
        
        return sumBelowLeft + sumBelowRight + node->val;
    }
    
    int findTilt(TreeNode* root) {
        int treeTilt = 0;
        
        tiltHelper(root, treeTilt);
        
        return treeTilt;
    }
};