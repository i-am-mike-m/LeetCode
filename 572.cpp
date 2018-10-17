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
    bool validateSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;        
        return (s->val == t->val) && validateSubtree(s->left, t->left) && validateSubtree(s->right, t->right);   
    }
    
    bool inOrder(TreeNode* s, TreeNode* t) {        
        if (!s) return false;
                        
        if (s->val == t->val) {
            if (validateSubtree(s, t)) return true;
        }
        
        if (inOrder(s->left, t)) return true;
        if (inOrder(s->right, t)) return true;
                        
        return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return inOrder(s, t);
    }
};