// Last updated: 6/14/2026, 9:36:01 AM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;

        for (char c : word) {
            if (islower(c)) lower.insert(c);
            else upper.insert(tolower(c));
        }

        int cnt = 0;

        for (char c : lower)
            if (upper.count(c)) cnt++;

        return cnt;
    }
};