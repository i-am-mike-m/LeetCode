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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (q.front() != NULL) {
            level.clear();
            while (q.front() != NULL) {
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            res.push_back(level);
            q.pop();
            q.push(NULL);
        }        
        
        return res;
    }
};