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
    void inorder(TreeNode* node, int*& prev, int& mindiff) {
        if (!node) return;
        
        inorder(node->left, prev, mindiff);
        
        if (prev == NULL) prev = &node->val;
        else {
            mindiff = min(mindiff, abs(node->val - *prev));
            prev = &node->val;
        }
        
        inorder(node->right, prev, mindiff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int* prev = NULL;
        int mindiff = numeric_limits<int>::max();
        inorder(root, prev, mindiff);
        
        return mindiff;
    }
};