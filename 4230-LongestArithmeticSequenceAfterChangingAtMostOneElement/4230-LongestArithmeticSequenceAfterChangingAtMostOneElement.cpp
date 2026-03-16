// Last updated: 3/16/2026, 11:10:46 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> f_pp, f_p, f_c, g_p, g_c;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            int d_act = nums[i] - nums[i-1];
            f_c.clear();
            g_c.clear();

            // 1) Exact match: extend f and g with actual diff
            f_c[d_act] = (f_p.count(d_act) ? f_p[d_act] : 1) + 1;

            // When g_p[d_act] is missing:
            //   i == 1 -> base 1 (only one prior element, no room for a "replace" prefix)
            //   i >= 2 -> base 2 (implicit: replace nums[i-1] giving a 2-elem prefix, extend by 1)
            int g_base = g_p.count(d_act) ? g_p[d_act] : (i >= 2 ? 2 : 1);
            g_c[d_act] = max(f_c[d_act], g_base + 1);

            // 2) Replace nums[i] to fit any d in f[i-1] (contributes to answer only)
            int best_rep = 0;
            for (auto& [d, len] : f_p)
                best_rep = max(best_rep, len + 1);

            // 3) Look-back-2: replace nums[i-1] so (nums[i-2], replaced, nums[i]) aligns with d2
            if (i >= 2) {
                long long diff2 = (long long)nums[i] - nums[i-2];
                if (diff2 % 2 == 0) {
                    int d2 = (int)(diff2 / 2);
                    // base: prior sequence ending at i-2 with d2, 0 replacements
                    // if none exists, treat as 1 (just nums[i-2]) -> +2 gives 3-element subarray
                    int base = f_pp.count(d2) ? f_pp[d2] : 1;
                    int val  = base + 2;
                    g_c[d2]  = max(g_c.count(d2) ? g_c[d2] : 0, val);
                }
            }

            for (auto& [d, len] : f_c) ans = max(ans, len);
            for (auto& [d, len] : g_c) ans = max(ans, len);
            ans = max(ans, best_rep);

            f_pp = f_p;
            f_p  = f_c;
            g_p  = g_c;
        }

        return ans;
    }
};

