// Last updated: 2/6/2026, 5:17:58 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        int need = k - 1;                 // we must pick (k-1) starts from indices >= 1
        if (need == 0) return nums[0];

        int L = 1;
        int R = min(n - 1, dist + 1);     // initial window [1 .. dist+1] (clamped if dist large)

        multiset<int> lo, hi;             // lo: need smallest, hi: rest
        long long sumLo = 0;

        auto moveHiToLo = [&]() {
            auto it = hi.begin();         // smallest in hi
            int v = *it;
            hi.erase(it);
            lo.insert(v);
            sumLo += v;
        };

        auto moveLoToHi = [&]() {
            auto it = prev(lo.end());     // largest in lo
            int v = *it;
            lo.erase(it);
            hi.insert(v);
            sumLo -= v;
        };

        auto rebalance = [&]() {
            while ((int)lo.size() < need) moveHiToLo();
            while ((int)lo.size() > need) moveLoToHi();
        };

        // build initial window
        for (int i = L; i <= R; ++i) {
            lo.insert(nums[i]);
            sumLo += nums[i];
        }
        while ((int)lo.size() > need) moveLoToHi();

        long long ans = (long long)nums[0] + sumLo;

        // if dist is so large that window already covers [1..n-1], no sliding needed
        if (R == n - 1) return ans;

        // slide window: newRight goes from (dist+2) to (n-1)
        for (int newR = dist + 2; newR <= n - 1; ++newR) {
            int outIdx = newR - (dist + 1);   // element leaving the window
            int x = nums[outIdx];
            int y = nums[newR];

            // remove x
            auto itLo = lo.find(x);
            if (itLo != lo.end()) {
                lo.erase(itLo);
                sumLo -= x;
            } else {
                auto itHi = hi.find(x);
                if (itHi != hi.end()) hi.erase(itHi);
            }

            // add y
            if (!lo.empty()) {
                int loMax = *prev(lo.end());
                if (y <= loMax) {
                    lo.insert(y);
                    sumLo += y;
                } else {
                    hi.insert(y);
                }
            } else {
                // lo empty can happen transiently after removal
                hi.insert(y);
            }

            rebalance();
            ans = min(ans, (long long)nums[0] + sumLo);
        }

        return ans;
    }
};
