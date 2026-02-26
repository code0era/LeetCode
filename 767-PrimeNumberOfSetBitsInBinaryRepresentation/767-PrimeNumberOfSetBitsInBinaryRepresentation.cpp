// Last updated: 2/26/2026, 9:09:07 PM
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bool isPrime[33] = {0};
        int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
        for (int p : primes) isPrime[p] = true;

        int ans = 0;
        for (int x = left; x <= right; x++) {
            int bits = __builtin_popcount((unsigned)x);
            if (isPrime[bits]) ans++;
        }
        return ans;
    }
};