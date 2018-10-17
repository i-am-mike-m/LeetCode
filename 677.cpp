/***********************

The inorder traversal is a classic tree traversal meaning visit left subtree, visit node, visit right subtree.

Sum: O(n*m) time where n is the length of the prefix and m is the size of the map
Insert: O(1)
O(1) additional space used by the methods. Number of inputs into the map drives real space usage.

***********************/

class MapSum {
public:
    unordered_map<string, int> map;
    
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (map.find(key) != map.end()) map.erase(key);
        map.insert({key,val});
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto each : map) {
            string comp = each.first;
            int valid = 1;
            for (int i = 0; i < prefix.size(); i++) {
                if (prefix[i] != comp[i]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) sum += each.second;
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */