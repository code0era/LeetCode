// Last updated: 1/16/2026, 8:19:54 PM
class Solution {
public:
    int climbStairs(int n, vector<int>& costs){
        vector <long long > dp(n+1 , LLONG_MAX);
        dp[0] =  0 ;
        for( int i   =1 ; i <= n ;  ++i){
            long  long cost_val = costs[i-1];
            if(i-1 >=0 && dp[i-1] != LLONG_MAX){
                dp[i] = min ( dp[i] , dp[i-1] +cost_val +1);
                
            }
            if(i-2 >=0 && dp[i-2] != LLONG_MAX){
                dp[i] = min ( dp[i] , dp[i-2] +cost_val +4);
                
            }
            if(i-3 >=0 && dp[i-3] != LLONG_MAX){
                dp[i] = min ( dp[i] , dp[i-3] +cost_val +9);
                
            }
        }
        return (int) dp[n];
    }
};