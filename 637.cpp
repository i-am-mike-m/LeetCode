/***********************

This problem is a good demonstration of the use of a queue to do level-order traversal of a tree.
We use NULL as a sentinel node to tell us when we have completely traversed one level.
Each time you encounter NULL you can add one level's average to the results. Pop the NULL and add a new one to the back of the queue.
If you immediately encounter a NULL right after pushing a NULL to the back of the queue it means there are no more nodes and the
traversal is complete.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> results;        
        if(!root) return results;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (q.front() != NULL) {
            double average = 0;
            int count = 0;
            
            while (q.front() != NULL) {
                TreeNode* current = q.front();
                q.pop();
                
                average += current->val;
                count++;
                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            
            q.pop();
            q.push(NULL);
            
            results.push_back(average / count);
        }
        
        return results;
    }
};