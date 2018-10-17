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
    int pathHelper(TreeNode* node, int sum, int main_path, unordered_map<int,int>& sub_paths_above) {
        if (!node) return 0;
        int count = 0;
        main_path += node->val;
        
        if (main_path == sum) count++;
        if (sub_paths_above.find(main_path - sum) != sub_paths_above.end()) count += sub_paths_above[main_path - sum];
        
        sub_paths_above[main_path]++;
        count += pathHelper(node->left, sum, main_path, sub_paths_above) + pathHelper(node->right, sum, main_path, sub_paths_above);
        sub_paths_above[main_path]--;
        
        return count;        
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> sub_paths_above;
        return pathHelper(root, sum, 0, sub_paths_above);
    }
};