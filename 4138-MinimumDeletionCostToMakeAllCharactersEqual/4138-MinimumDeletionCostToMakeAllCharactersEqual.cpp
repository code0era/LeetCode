// Last updated: 1/16/2026, 8:19:45 PM
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        auto a = s;   

        long long t = 0;
        vector<long long> f(26, 0);

        for (int i = 0; i < s.size(); i++) {
            t += cost[i];
            f[s[i] - 'a'] += cost[i];
        }

        long long m = 0;
        for (int i = 0; i < 26; i++) {
            m = max(m, f[i]);
        }

        return t - m;
    }
};