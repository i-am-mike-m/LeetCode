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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return new TreeNode(v);
        if (d == 1) {
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (d != 2) {
            while (q.front() != NULL) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            q.pop();
            q.push(NULL);
            d--;
        }
        while (q.front()!= NULL) {
            TreeNode* current = q.front();
            q.pop();
            TreeNode* left = current->left;
            TreeNode* right = current->right;
            current->left = new TreeNode(v);
            current->left->left = left;
            current->right = new TreeNode(v);
            current->right->right = right;
        }
        return root;
    }
};