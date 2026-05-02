// Last updated: 5/2/2026, 9:55:20 PM
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        int count = 0;
5        for (int i = 1; i <= n; i++) {
6            if (isGood(i)) count++;
7        }
8        return count;
9    }
10
11private:
12    bool isGood(int num) {
13        bool hasRotatingDigit = false;
14        while (num > 0) {
15            int digit = num % 10;
16            
17            if(digit == 3 || digit == 4 || digit == 7) return false;
18            
19            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
20                hasRotatingDigit = true;
21            }
22            num /= 10;
23        }
24        return hasRotatingDigit;
25    }
26};