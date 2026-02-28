// Last updated: 2/28/2026, 1:31:01 PM
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;

        if (initial_zeros == 0) return 0;

        set<int> unvisited[2];
        for (int i = 1; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> q;
        q.push({initial_zeros, 0});
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            int min_x = max(0, k - (n - cur));
            int max_x = min(cur, k);

            if (min_x > max_x) continue;

            int L = cur + k - 2 * max_x;
            int R = cur + k - 2 * min_x;

            if (L <= 0 && 0 <= R && (0 - L) % 2 == 0) {
                return steps + 1;
            }

            int p = L % 2;
            auto it = unvisited[p].lower_bound(L);
            while (it != unvisited[p].end() && *it <= R) {
                q.push({*it, steps + 1});
                it = unvisited[p].erase(it);
            }
        }

        return -1;
    }
};