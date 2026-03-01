// Last updated: 3/1/2026, 9:34:43 AM
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};