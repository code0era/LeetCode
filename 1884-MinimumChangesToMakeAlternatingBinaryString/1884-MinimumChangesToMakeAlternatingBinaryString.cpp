// Last updated: 3/5/2026, 5:55:08 AM
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        // cost to match pattern "1010..."
        int cost10 = 0; 

        for (int i = 0; i < n; ++i) {
            // If s[i] == (i % 2), it matches "1010..." pattern
            if (s[i] - '0' == i % 2) {
                cost10++;
            }
        }

        // cost to match "0101..." is remaining mismatches
        int cost01 = n - cost10;

        return min(cost10, cost01);
    }
};