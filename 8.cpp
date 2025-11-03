class Solution {
public:
    int myAtoi(std::string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        long long result = 0;
        
        while (i < n) {
            char current_char = s[i];
            
            if (current_char < '0' || current_char > '9') {
                break;
            }
            
            int digit = current_char - '0';
            
            result = result * 10 + digit;
            
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && (-result) < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return (int)(result * sign);
    }
};