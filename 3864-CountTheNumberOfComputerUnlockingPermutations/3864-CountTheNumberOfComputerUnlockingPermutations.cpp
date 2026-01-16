// Last updated: 1/16/2026, 8:20:03 PM
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;
    // Precomputed factorials and inverse factorials for modular arithmetic
    vector<long long> fact;
    vector<long long> invFact;

    // Modular exponentiation (a^b % mod)
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular inverse (a^-1 % mod) using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    // Precompute factorials and inverse factorials up to n
    void precompute(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // Modular combination (nCk % mod)
    long long nCr_mod(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r; // Optimization
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

public:
    /**
     * Finds the number of valid permutations for unlocking computers.
     * A computer i is unlocked by computer j if j < i and complexity[j] < complexity[i].
     * Computer 0 is the root and is initially unlocked.
     */
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (n == 0) return 0;

        precompute(n);

        // 1. Group computer indices by complexity and identify unique complexities
        map<int, int> complexity_counts;
        for (int c : complexity) {
            complexity_counts[c]++;
        }

        vector<int> unique_complexities;
        for (auto const& [comp, count] : complexity_counts) {
            unique_complexities.push_back(comp);
        }

        int root_complexity = complexity[0];
        long long result = 1;
        int n_prev = 0; // Total count of computers from previous (lower) complexity groups

        // 2. Pre-check for impossibility (The critical constraint)
        // If complexity[i] = complexity[0] for any i > 0, computer i cannot be unlocked 
        // because it requires a witness j < i with complexity[j] < complexity[i], which 
        // computer 0 (the only initially unlocked one) cannot provide.
        for (int comp : unique_complexities) {
            if (comp <= root_complexity && complexity_counts[comp] > 1) {
                return 0;
            }
        }

        // 3. Dynamic Counting by group (Iterate through complexities in ascending order)
        for (int comp : unique_complexities) {
            int n_m = complexity_counts[comp];
            int n_total = n_prev + n_m;

            long long factor;

            if (comp == root_complexity) {
                // Case: Root Group (C_r).
                // Index 0 must be the first element among all computers considered up to this group (C_1 U ... U C_r).
                // The probability of this is 1/N_total.
                // Ways to interleave = (1/N_total) * C(N_total, n_m).
                factor = modInverse(n_total) * nCr_mod(n_total, n_m) % MOD;
            } else {
                // Case: Complexity v_m != v_r.
                // Each computer in C_m must be unlocked by a computer in W_{m-1} = C_1 U ... U C_{m-1}.
                // This means the first element of the combined sequence (W_{m-1} U C_m) must come from W_{m-1}.
                // The probability is N_prev / N_total.
                // Ways to interleave = (N_prev / N_total) * C(N_total, n_m).
                factor = (n_prev * modInverse(n_total)) % MOD * nCr_mod(n_total, n_m) % MOD;
            }
            
            // Apply the factor for relative ordering, and multiply by n_m! for the internal
            // ordering of the n_m computers within their chosen positions.
            result = (result * factor) % MOD;
            result = (result * fact[n_m]) % MOD;

            n_prev = n_total;
        }

        return result;
    }
};