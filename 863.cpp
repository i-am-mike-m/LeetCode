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
    void searchBelow(TreeNode* node, vector<int>& nodes, int K) {
        if (!node) return;
        if (K == 0) {
            nodes.push_back(node->val);
            return;
        }
        searchBelow(node->left, nodes, K - 1);
        searchBelow(node->right, nodes, K - 1);    
    }
    
    int traverseToTarget(TreeNode* node, TreeNode* target, vector<int>& nodes, int K, bool& found) {
        if (!node) return K;
        
        if (node == target) {
            found = true;
            searchBelow(node, nodes, K);
            return K - 1;
        }
        
        if (!found) {
            K = traverseToTarget(node->left, target, nodes, K, found);
            if (found) {
                searchBelow(node->right, nodes, K - 1);
                if (K == 0) nodes.push_back(node->val);
                return K - 1;
            }
        }
        if (!found) {
            K = traverseToTarget(node->right, target, nodes, K, found);
            if (found) {
                searchBelow(node->left, nodes, K - 1);
                if (K == 0) nodes.push_back(node->val);
                return K - 1;
            }
        }
                
        return K;        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> nodes;
        bool found = false;
        traverseToTarget(root, target, nodes, K, found);
        return nodes;
    }
};