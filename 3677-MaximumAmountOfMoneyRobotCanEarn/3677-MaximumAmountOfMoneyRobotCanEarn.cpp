// Last updated: 4/3/2026, 7:58:57 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int INF = 1e9;

        // dp[i][j][k] -> max profit at cell (i, j) with k neutralizations used
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int val = grid[i][j];

                for(int k = 0; k < 3; ++k) {
                    // Base Case: Starting Point
                    if (i == 0 && j == 0) {
                        dp[i][j][0] = val;
                        if (k > 0) {
                            dp[i][j][k] = max(val, 0); 
                        }
                        continue;
                    }

                    // 1. Standard Move (Add current cell value to previous best)
                    int from_top = (i > 0) ? dp[i - 1][j][k] : -INF;
                    int from_left = (j > 0) ? dp[i][j - 1][k] : -INF;
                    
                    if (from_top != -INF || from_left != -INF) {
                        dp[i][j][k] = max(from_top, from_left) + val;
                    }

                    // 2. Use Neutralization (Treat current negative cell as 0)
                    if (k > 0 && val < 0) {
                        int prev_top = (i > 0) ? dp[i - 1][j][k - 1] : -INF;
                        int prev_left = (j > 0) ? dp[i][j - 1][k - 1] : -INF;
                        
                        if (prev_top != -INF || prev_left != -INF) {
                            dp[i][j][k] = max(dp[i][j][k], max(prev_top, prev_left));
                        }
                    }
                }
            }
        }

        return *max_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
    }
};