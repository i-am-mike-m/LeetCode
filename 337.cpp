/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    pair<int,int> robChildrenOrParent(TreeNode* node) {
        if (!node) return make_pair(0,0);
        
        pair<int,int> left = robChildrenOrParent(node->left);
        pair<int,int> right = robChildrenOrParent(node->right);
        
        return (make_pair(node->val + left.second + right.second, max(right.first, right.second) + max(left.first, left.second)));
    }
    
    int rob(TreeNode* root) {
        return max(robChildrenOrParent(root).first, robChildrenOrParent(root).second);
    }
};