// DO IT ITERATIVELY FOR A CHALLENGE

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> results;
        if (!root) return results;
        
        stack<Node*> s;
        s.push(root);        
        
        while (!s.empty()) {
            Node* top = s.top();
            s.pop();
            results.push_back(top->val);
            
            for (auto each : top->children) {
                if(each) s.push(each);
            }                        
        }
        
        reverse(results.begin(), results.end());
        
        return results;
    }
};