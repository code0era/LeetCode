// Last updated: 2/11/2026, 7:58:00 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int l, r;
        int mn, mx;
        int lazy;
    };

    struct SegTree {
        vector<Node> tr;
        SegTree(int n) : tr((n + 1) * 4) {
            build(1, 0, n);
        }

        void build(int u, int l, int r) {
            tr[u].l = l; tr[u].r = r;
            tr[u].mn = tr[u].mx = 0;
            tr[u].lazy = 0;
            if (l == r) return;
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
        }

        void apply(int u, int v) {
            tr[u].mn += v;
            tr[u].mx += v;
            tr[u].lazy += v;
        }

        void pushdown(int u) {
            if (tr[u].lazy != 0) {
                apply(u << 1, tr[u].lazy);
                apply(u << 1 | 1, tr[u].lazy);
                tr[u].lazy = 0;
            }
        }

        void pushup(int u) {
            tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
            tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
        }

        // range add [l, r]
        void modify(int u, int l, int r, int v) {
            if (tr[u].l >= l && tr[u].r <= r) {
                apply(u, v);
                return;
            }
            pushdown(u);
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (l <= mid) modify(u << 1, l, r, v);
            if (r > mid)  modify(u << 1 | 1, l, r, v);
            pushup(u);
        }

        // find smallest index pos where prefix[pos] == target
        int query(int u, int target) {
            if (tr[u].l == tr[u].r) return tr[u].l;
            pushdown(u);
            int lc = u << 1, rc = u << 1 | 1;
            if (tr[lc].mn <= target && target <= tr[lc].mx) {
                return query(lc, target);
            }
            return query(rc, target);
        }
    };

public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        SegTree st(n);
        unordered_map<int,int> last; // value -> last position (1-indexed)

        int now = 0;  // current prefix balance
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int det = (x & 1) ? 1 : -1;

            // remove old contribution if x appeared before
            auto it = last.find(x);
            if (it != last.end()) {
                st.modify(1, it->second, n, -det);
                now -= det;
            }

            // add new contribution at position i
            last[x] = i;
            st.modify(1, i, n, det);
            now += det;

            int pos = st.query(1, now);
            ans = max(ans, i - pos);
        }
        return ans;
    }
};