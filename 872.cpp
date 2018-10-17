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
    void getLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return;
        }
        if (node->left) getLeaves(node->left, leaves);
        if (node->right) getLeaves(node->right, leaves);
        
        return;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        
        vector<int> leaves1;
        vector<int> leaves2;
        
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        
        if (leaves1.size() != leaves2.size()) return false;
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) return false;
        }
        
        return true;
    }
};