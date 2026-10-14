#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string ans = "";
        int carry = 0;
        
        // Pointers for the end of both strings
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        
        // Loop as long as there are digits to process or a carry remains
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += num1[i] - '0'; // Convert character to integer
                i--;
            }
            if (j >= 0) {
                carry += num2[j] - '0'; // Convert character to integer
                j--;
            }
            
            // Append the last digit of the current sum to the result string
            ans += (carry % 10) + '0';
            
            // Compute the new carry
            carry /= 10;
        }
        
        // Since we added from right to left, the result string is reversed
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
