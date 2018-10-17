/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    queue<TreeNode*> workingLevel;
    TreeNode* root;
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        
        TreeNode* current = root;
        workingLevel.push(root);
        while (current->left && current->right) {
            workingLevel.push(current->left);
            workingLevel.push(current->right);
            workingLevel.pop();
            current = workingLevel.front();
        }
    }
    
    int insert(int v) {
        TreeNode* current = workingLevel.front();
        TreeNode* parent = workingLevel.front();
        
        if (!current->left) current->left = new TreeNode(v);
        else current->right = new TreeNode(v);
        
        while (current->left && current->right) {
            workingLevel.push(current->left);
            workingLevel.push(current->right);
            workingLevel.pop();
            current = workingLevel.front();
        }
        
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */