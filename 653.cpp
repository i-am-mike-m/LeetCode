/***********************

There are several ways to solve this problem. This one doesn't actually use the BST property but does use
the fact that an inorder of a BST is a sorted array. Despite the BST there is no log(n) solution. The BST
solution does a binary search on the remainder for each node to find a complement, resulting in a worst
case complexity of nlog(h) where n is the number of nodes and h is the height of the tree.

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
    void inorder(TreeNode* node, vector<int>& order) {
        if (!node) return;
        inorder(node->left, order);
        order.push_back(node->val);
        inorder(node->right, order);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> order;
        inorder(root, order);
        
        int i = 0, j = order.size()-1;
        int current;
        while (i < j) {
            current = order[i] + order[j];
            if (current == k) return true;
            else if (current > k) j--;
            else i++;
        }
        
        return false;
    }
};