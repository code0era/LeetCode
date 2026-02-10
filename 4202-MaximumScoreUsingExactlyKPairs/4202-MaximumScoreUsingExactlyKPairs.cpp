// Last updated: 2/11/2026, 12:52:51 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    long long dp[101][101][101];
    const long long INF = 1e18;

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int p = 0; p <= k; ++p)
                    dp[i][j][p] = -INF;

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j][0] = 0;

        for (int p = 1; p <= k; ++p) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    long long res = max(dp[i - 1][j][p], dp[i][j - 1][p]);
                    if (dp[i - 1][j - 1][p - 1] != -INF) {
                        res = max(res, dp[i - 1][j - 1][p - 1] + (long long)nums1[i - 1] * nums2[j - 1]);
                    }
                    dp[i][j][p] = res;
                }
            }
        }

        return dp[n][m][k];
    }
};