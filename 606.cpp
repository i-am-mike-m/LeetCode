/***********************

Cumbersome problem that isn't a very good problem. Comes down to very careful tracking of cases.

This is a fun one-line answer that I grabbed on the discussion thread. Meh at this problem.

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
    string tree2str(TreeNode* t) {
        return !t ? "" : to_string(t->val) + (t->left ? "(" + tree2str(t->left) + ")" : t->right ? "()" : "")
                                           + (t->right ? "(" + tree2str(t->right) + ")" : "");
    }
};