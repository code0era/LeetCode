// Last updated: 3/29/2026, 8:59:32 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n);  
        dp[0].push_back(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                vector<int> candidates;
                
                if (i > 0) {
                    for (int val : dp[j]) {
                        candidates.push_back(val ^ grid[i][j]);
                    }
                }     
                if (j > 0) {
                    for (int val : dp[j - 1]) {
                        candidates.push_back(val ^ grid[i][j]);
                    }
                }                
                sort(candidates.begin(), candidates.end());
                candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
                
                dp[j] = std::move(candidates);
            }
        }        
        return dp[n - 1][0];
    }
};
