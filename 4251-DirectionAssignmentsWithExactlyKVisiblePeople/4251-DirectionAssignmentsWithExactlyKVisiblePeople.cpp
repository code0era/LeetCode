// Last updated: 3/29/2026, 8:59:22 AM
class Solution {
    const long long MOD = 1000000007;
    
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }

public:
    int countVisiblePeople(int n, int pos, int k) {
    
        if (k > n - 1) return 0;
        
        long long num = 1, den = 1;
        for (int i = 0; i < k; i++) {
            num = num * ((n - 1 - i) % MOD) % MOD;
            den = den * (i + 1) % MOD;
        }
        
        long long comb = num * power(den, MOD - 2, MOD) % MOD;
        return (2LL * comb) % MOD;
    }
};
