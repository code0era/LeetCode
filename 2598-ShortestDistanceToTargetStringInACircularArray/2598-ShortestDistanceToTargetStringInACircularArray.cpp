// Last updated: 4/25/2026, 12:59:04 AM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = 1e9;
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min({ans, dist, n - dist});
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};