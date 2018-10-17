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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) return results;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (q.size() > 1) {
            vector<int> level;
            while (q.front() != NULL) {
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            results.push_back(level);
            q.pop();
            q.push(NULL);
        }
        
        reverse(results.begin(), results.end());        
        return results;
    }
};