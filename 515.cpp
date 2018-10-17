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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;        
        q.push(root);
        q.push(NULL);
        
        while (q.size() > 1) {
            int levelmax = numeric_limits<int>::min();
            while (q.front() != NULL) {                
                TreeNode* current = q.front();
                q.pop();
                
                levelmax = max(levelmax, current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            res.push_back(levelmax);
            q.pop();
            q.push(NULL);
        }
        
        return res;
    }
};