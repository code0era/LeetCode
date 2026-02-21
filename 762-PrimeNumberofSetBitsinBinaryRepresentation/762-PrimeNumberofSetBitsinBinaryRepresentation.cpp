// Last updated: 2/21/2026, 9:15:34 AM
1class Solution {
2public:
3    int countPrimeSetBits(int left, int right) {
4        bool isPrime[33] = {0};
5        int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
6        for (int p : primes) isPrime[p] = true;
7
8        int ans = 0;
9        for (int x = left; x <= right; x++) {
10            int bits = __builtin_popcount((unsigned)x);
11            if (isPrime[bits]) ans++;
12        }
13        return ans;
14    }
15};