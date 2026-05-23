// Last updated: 5/23/2026, 10:06:02 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        int st[205][205][8], lg[205];
        
        lg[1] = 0;
        for (int i = 2; i <= 200; ++i) lg[i] = lg[i / 2] + 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) st[i][j][0] = matrix[i][j];
            for (int k = 1; (1 << k) <= m; ++k) {
                for (int j = 0; j + (1 << k) <= m; ++j) {
                    st[i][j][k] = max(st[i][j][k - 1], st[i][j + (1 << (k - 1))][k - 1]);
                }
            }
        }
        
        auto query = [&](int r, int L, int R) {
            L = max(0, L); R = min(m - 1, R);
            if (L > R) return -1;
            int k = lg[R - L + 1];
            return max(st[r][L][k], st[r][R - (1 << k) + 1][k]);
        };
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int x = matrix[r][c];
                if (x == 0) continue;
                bool ok = true;
                for (int i = max(0, r - x); i <= min(n - 1, r + x) && ok; ++i) {
                    int L = c - x, R = c + x;
                    if (abs(i - r) == x) L++, R--;
                    if (query(i, L, R) > x) ok = false;
                }
                if (ok) ans++;
            }
        }
        return ans;
    }
};