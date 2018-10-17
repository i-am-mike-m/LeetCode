class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1) {                       
            // Infinite Loop Check
            if (seen.find(n) != seen.end()) return false;
            seen.insert(n); 
            
            int temp = 0;
            while (n) {
                int add = n % 10;
                temp += pow(add, 2);                
                n /= 10;                
            }
            n = temp;                        
        }
        
        return true;
    }
};