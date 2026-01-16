// Last updated: 1/16/2026, 8:20:46 PM
class Solution {
public:
    int dp[32];

    Solution() {
        for (int i = 0; i < 32; i++) dp[i] = -1;
    }

    int fib(int n) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
};
