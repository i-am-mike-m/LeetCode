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
    pair<int,int> uniHelper(TreeNode* node, int& longest) {
        if (!node) return make_pair(INT_MIN, 0);
        
        pair<int, int> left = uniHelper(node->left, longest);
        pair<int, int> right = uniHelper(node->right, longest);
        
        int countRootedHere = 1;
        if (left.first == node->val) countRootedHere += left.second;
        if (right.first == node->val) countRootedHere += right.second;
        if (countRootedHere - 1 > longest) longest = countRootedHere - 1;
        
        int countReturn = 1;
        if (left.first == node->val && right.first == node->val) return make_pair(node->val, countReturn + max(left.second, right.second));
        else if (left.first == node->val) return make_pair(node->val, countReturn + left.second);
        else if (right.first == node->val) return make_pair(node->val, countReturn + right.second);
        else return (make_pair(node->val, countReturn));                
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;
        uniHelper(root, longest);
        return longest;
    }
};