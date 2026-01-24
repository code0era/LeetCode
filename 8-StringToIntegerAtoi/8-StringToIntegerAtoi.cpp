// Last updated: 1/25/2026, 3:08:07 AM
#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        int sign = 1;
        int ans = 0;

        // 1. Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and check overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before updating ans
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};