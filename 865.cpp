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
    pair<TreeNode*, int> subHelper(TreeNode* node, int& maxDepth, int depth) {
        TreeNode* retNode = NULL;
        if (!node) return make_pair(retNode, -1);
        maxDepth = max(maxDepth, depth);
        
        pair<TreeNode*, int> left, right;
        
        if (!node->left && !node->right) {
            return depth == maxDepth ? make_pair(node, depth) : make_pair(retNode, -1);
        }
        else {
            left = subHelper(node->left, maxDepth, depth + 1);
            right = subHelper(node->right, maxDepth, depth + 1);
        }
        
        if (left.second == maxDepth && right.second == maxDepth) return make_pair(node, maxDepth);
        else if (left.second == maxDepth) {
            if (left.first == retNode) return make_pair(node, left.second);
            else return left;
        }
        else if (right.second == maxDepth) {
            if (right.first == retNode) return make_pair(node, right.second);
            else return right;
        }
        else return make_pair(retNode, -1);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;
        if (!root->right && !root->left) return root;
        int maxDepth = 0;
        pair<TreeNode*, int> res = subHelper(root, maxDepth, 0);
        return res.first;
    }
};