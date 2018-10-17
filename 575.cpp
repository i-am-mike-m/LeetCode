/***********************

Use of an unordered_set will make it easy to determine how many types of candy are present. The sister may either receive the number
of types present or half the number of candies, whichever is less.

O(n) time
O(n) space

***********************/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> types;
        for (auto each : candies) types.insert(each);
        
        return min(types.size(), candies.size()/2);            
    }
};