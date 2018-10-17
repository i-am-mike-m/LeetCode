/***********************

Excellent tree problem!

O(n) time
O(n) space

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* t1 = NULL;
            TreeNode* t2 = NULL;
            t1 = q1.front();
            q1.pop();
            t2 = q2.front();
            q2.pop();
            
            if (!t1 && !t2) continue;
            if (!t1 && t2) return false;
            if (t1 && !t2) return false;            
            if (t1->val != t2->val) return false;
            
            if(t1) {
                q1.push(t1->left);
                q1.push(t1->right);
            }
            if (t2) {
                q2.push(t2->left);
                q2.push(t2->right);
            }            
        }
        
        return (q1.empty() && q2.empty());
    }
};