// Last updated: 3/1/2026, 9:34:15 AM
class Solution {
public:
    int minCost(int n) {
        vector<int > dp(n+1,0);
        for(int x = 2 ; x<=n ; x++){
            dp[x] = INT_MAX;
            for(int a = 1 ; a< x ; a++){
                int   b = x -a ;
                int cost = a*b+dp[a] +dp[b];
                dp[x] = min(dp[x]  ,cost);
            }
        }
        return dp[n];
    }
};