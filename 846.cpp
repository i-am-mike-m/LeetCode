class Solution {
public:
    void mapCheck(vector<int>& hand, unordered_map<int,int>& m, int W, int i) {       
        int num = hand[i];
        for (int j = 0; j < W; j++) {
            if (m.find(num + j) == m.end()) return;
        }
        for (int j = 0; j < W; j++) {
            m[num + j]--;
            if (m[num + j] == 0) m.erase(num + j);
        }
    }
    
    bool isNStraightHand(vector<int>& hand, int W) {
        unordered_map<int,int> m;
        if (hand.size() == 0) return W == 0;
        else if (hand.size() % W != 0) return false;
        
        sort(hand.begin(), hand.end());
        for (auto each : hand) m[each]++;                
        
        for (int i = 0; i < hand.size(); i++) {
            mapCheck(hand, m, W, i);
        }
        
        return m.empty();
    }
};