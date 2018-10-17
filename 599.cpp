class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int size1 = list1.size();
        int size2 = list2.size();        
        int minIndex = INT_MAX;
        unordered_map<string,int> common;
        vector<string> results;
        
        /*
            To save space I'm using the '+ 10000' as a flag value in the map, as it
            is far above the index limit set by the problem. Items found in both sets
            have this '+ 10000' subtracted, flagging values under 10000 as common strings.            
        */
        for (int i = 0; i < size1; i++) {
            common[list1[i]] = i + 10000;
        }
        for (int i = 0; i < size2; i++) {
            if (common.find(list2[i]) != common.end()) {
                common[list2[i]] += (i - 10000);
                minIndex = min(minIndex, common[list2[i]]);
            }
        }
        for (auto each : common) {
            if (each.second == minIndex) results.push_back(each.first);
        }
        
        return results;
    }
};