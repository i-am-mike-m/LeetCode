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
    void inorder(TreeNode* node, pair<int,int>& leftpair, int level) {
        if (!node) return;
        inorder(node->left, leftpair, level + 1);        
        if (leftpair.first < level) {
            leftpair.second = node->val;        
            leftpair.first = level;
        }
        inorder(node->right, leftpair, level + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> leftpair (-1, -1);
        inorder(root, leftpair, 0);
        return leftpair.second;
    }
};