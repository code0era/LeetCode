// Last updated: 2/26/2026, 9:09:11 PM
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = (int)s.size();
        int prev = 0, cur = 1, ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
        }
        ans += min(prev, cur);
        return ans;
    }
};