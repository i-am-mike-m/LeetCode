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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        
        for (int i = 0; i < nums.size(); i++) {
            TreeNode* node = new TreeNode(nums[i]);
            while (!s.empty() && s.back()->val < node->val) {
                node->left = s.back();
                s.pop_back();
            }
            if (!s.empty()) {
                s.back()->right = node;
            }
            s.push_back(node);
        }
        return s.front();
    }
};