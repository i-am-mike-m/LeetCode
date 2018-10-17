// Watch out for requirement of problem solution to use 1-indexing instead of 0-indexing

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> results(2,0);
        int front = 0;
        int back = numbers.size()-1;
        
        while (front < back) {
            if (numbers[front] + numbers[back] == target) {
                results[0] = front + 1;
                results[1] = back + 1;
                break;
            }
            else if (numbers[front] + numbers[back] > target) back--;
            else front++;
        }
        
        return results;
    }
};