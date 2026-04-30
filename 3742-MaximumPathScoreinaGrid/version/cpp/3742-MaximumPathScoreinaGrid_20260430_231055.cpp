// Last updated: 4/30/2026, 11:10:55 PM
1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int inf = 1 << 30;
7        vector f(m, vector(n, vector<int>(k + 1, -1)));
8
9        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
10            if (i < 0 || j < 0 || k < 0) {
11                return -inf;
12            }
13            if (i == 0 && j == 0) {
14                return 0;
15            }
16            if (f[i][j][k] != -1) {
17                return f[i][j][k];
18            }
19
20            int res = grid[i][j];
21            int nk = k;
22            if (grid[i][j] > 0) {
23                --nk;
24            }
25
26            int a = dfs(i - 1, j, nk);
27            int b = dfs(i, j - 1, nk);
28            res += max(a, b);
29
30            return f[i][j][k] = res;
31        };
32
33        int ans = dfs(m - 1, n - 1, k);
34        return ans < 0 ? -1 : ans;
35    }
36};