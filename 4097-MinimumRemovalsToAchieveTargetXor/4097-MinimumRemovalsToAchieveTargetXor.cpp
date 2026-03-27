// Last updated: 3/28/2026, 1:27:43 AM
class Solution {
public:
    int minRemovals(vector<int>& a, int target) {
        int n = a.size(), m = n / 2;
        unordered_map<int,int> mp;

        // left half
        for(int mask = 0; mask < (1 << m); mask++) {
            int x = 0, cnt = 0;
            for(int i = 0; i < m; i++)
                if(mask >> i & 1) x ^= a[i], cnt++;
            mp[x] = max(mp[x], cnt);
        }

        int best = -1;

        // right half
        for(int mask = 0; mask < (1 << (n - m)); mask++) {
            int x = 0, cnt = 0;
            for(int i = 0; i < n - m; i++)
                if(mask >> i & 1) x ^= a[m + i], cnt++;

            if(mp.count(target ^ x))
                best = max(best, cnt + mp[target ^ x]);
        }

        return best == -1 ? -1 : n - best;
    }
};