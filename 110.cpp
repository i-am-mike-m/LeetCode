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
    int balanceBelow(TreeNode* node, bool& balance) {
        if (!node || !balance) return 0;
        
        int left = balanceBelow(node->left, balance);
        int right = balanceBelow(node->right, balance);
        
        if (abs(right - left) > 1) balance = false;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        balanceBelow(root, balance);
        return balance;
    }
};