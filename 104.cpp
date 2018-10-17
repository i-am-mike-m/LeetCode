/***********************

This is a great problem. By sending a value of the current depth + 1 down to the next level and returning 'depth - 1' in the event
of a NULL node, you account for any calls where there is no left or right child. This could also be done using two variables and an
if statement to only make the recursive call if the child exists, but I like the clean reading of the way I have it here.

O(n) time
O(h) space - h is the maximum depth of the tree. This space complexity is tied to the recursive call stack.

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
    int depthHelper(TreeNode* node, int depth) {
        if (!node) return depth - 1;
        
        depth = max(depthHelper(node->left, depth + 1), depthHelper(node->right, depth + 1));
        
        return depth;
    }
    
    int maxDepth(TreeNode* root) {
        return depthHelper(root, 1);
    }
};