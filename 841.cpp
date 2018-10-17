class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> toVisit;
        queue<int> visiting;
        for (int i = 1; i < rooms.size(); i++) toVisit.insert(i);
        visiting.push(0);
        
        while (!visiting.empty()) {
            int current = visiting.front();
            visiting.pop();
            for (auto each : rooms[current]) {
                if (toVisit.find(each) != toVisit.end()) {
                    visiting.push(each);
                    toVisit.erase(each);
                }
            }
        }
        return toVisit.empty();
    }
};