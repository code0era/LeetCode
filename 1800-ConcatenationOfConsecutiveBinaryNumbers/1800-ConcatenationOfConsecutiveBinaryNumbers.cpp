// Last updated: 2/28/2026, 9:19:38 PM
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1'000'000'007;
        long long ans = 0;
        int bits = 0; // current bit-length
        
        for (int i = 1; i <= n; i++) {
            // if i is power of two, bit-length increases by 1
            if ((i & (i - 1)) == 0) bits++;
            
            ans = ((ans << bits) % MOD + i) % MOD;
        }
        return (int)ans;
    }
};