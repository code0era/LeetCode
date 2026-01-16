// Last updated: 1/16/2026, 8:20:33 PM
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long dpA = 6; // all 3 different
        long long dpB = 6; // two same

        for (int i = 2; i <= n; i++) {
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
