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
    int postOrder(TreeNode* node, unordered_map<int,int>& mp) {
        if (!node) return 0;
        
        int leftSum = postOrder(node->left, mp);
        int rightSum = postOrder(node->right, mp);
        
        int current = node->val + leftSum + rightSum;
        mp[current]++;
        
        return current;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        vector<int> res;
        if (!root) return res;
        
        postOrder(root, mp);
        int maxCount = 0;
        for (auto each : mp) {
            if (each.second >= maxCount) {
                if (each.second > maxCount) res.clear();
                res.push_back(each.first);
                maxCount = each.second;
            }
        }
        
        return res;
    }
};