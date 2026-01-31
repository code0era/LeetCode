// Last updated: 1/31/2026, 9:35:24 PM
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

class Solution {
public:
    long long minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] stores the min cost to reach cell (i, j)
        // We use two layers: current teleport count and previous
        vector<vector<long long>> dp(m, vector<long long>(n, LLONG_MAX / 2));
        
        // Base Case: 0 teleports (Standard Grid DP)
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
        
        // Pre-group cells by value for efficient teleport calculation
        // Map: value -> list of coordinates {r, c}
        // We use a map with greater<int> to iterate in descending order automatically
        map<int, vector<pair<int, int>>, greater<int>> valGroups;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                valGroups[grid[i][j]].push_back({i, j});
            }
        }

        long long ans = dp[m-1][n-1];

        // Iterate for k teleports
        for (int t = 1; t <= k; ++t) {
            vector<vector<long long>> next_dp(m, vector<long long>(n, LLONG_MAX / 2));
            long long min_prev_cost = LLONG_MAX / 2;
            
            // 1. Teleport Moves
            // Iterate values from High -> Low.
            // If we are at value V, we can teleport FROM any cell with value >= V.
            // min_prev_cost tracks the min cost among all cells processed so far (which are all >= V).
            for (auto& [val, cells] : valGroups) {
                // Update min_prev_cost with costs from the PREVIOUS layer (t-1)
                for (auto& p : cells) {
                    min_prev_cost = min(min_prev_cost, dp[p.first][p.second]);
                }
                // Apply teleport: Cost is 0, so we just take min_prev_cost
                for (auto& p : cells) {
                    next_dp[p.first][p.second] = min_prev_cost;
                }
            }
            
            // 2. Walk Moves (Right/Down)
            // Propagate the teleported values using normal moves within the current layer 't'
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) next_dp[i][j] = min(next_dp[i][j], next_dp[i-1][j] + grid[i][j]);
                    if (j > 0) next_dp[i][j] = min(next_dp[i][j], next_dp[i][j-1] + grid[i][j]);
                }
            }
            
            dp = next_dp;
            ans = min(ans, dp[m-1][n-1]);
        }
        
        return ans;
    }
};