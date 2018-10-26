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
    vector<int> rightSideView(TreeNode* root) {        
        vector<int> res;
        queue<TreeNode*> q;
        if (!root) return res;
        
        q.push(root);
        q.push(NULL);
        while (q.front() != NULL) {
            res.push_back(q.front()->val);
            while (q.front() != NULL) {
                TreeNode* current = q.front();
                q.pop();
                if (current->right) q.push(current->right);
                if (current->left) q.push(current->left);                
            }
            q.pop();
            q.push(NULL);            
        }
        
        return res;        
    }
};