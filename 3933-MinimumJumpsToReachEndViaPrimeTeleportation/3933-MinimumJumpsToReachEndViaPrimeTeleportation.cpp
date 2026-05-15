// Last updated: 5/15/2026, 8:34:01 PM
class Solution {
public:

    vector<int> sieve(int mx) {

        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= mx; j += i) {

                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        return spf;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf = sieve(mx);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {
                factors.insert(spf[x]);
                x /= spf[x];
            }

            for (auto p : factors)
                mp[p].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return jumps;

                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                int val = nums[i];

                if (val >= 2 && spf[val] == val) {

                    for (int nxt : mp[val]) {

                        if (!vis[nxt]) {
                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                    }

                    mp.erase(val);
                }
            }

            jumps++;
        }

        return -1;
    }
};