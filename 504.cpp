class Solution {
public:
    int getPower(int num) {
        int power = 0;
        while (pow(7,power + 1) <= num) power++;
        
        return power;
    }
    
    string convertToBase7(int num) {
        bool isNeg = false;
        if (num < 0) {
            num *= -1;
            isNeg = true;
        }
        
        int power = getPower(num);
        int seven = 0;
        
        while (power > -1) {
            int divisor = pow(7, power);
            seven += (num / divisor);
            num %= divisor;
                        
            if(power) seven *= 10;            
            power--;
        }
        if (isNeg) seven *= -1;
        
        return to_string(seven);
    }
};