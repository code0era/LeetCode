// Last updated: 1/24/2026, 5:50:11 AM
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // 1. Doubly Linked List Arrays
        vector<int> L(n), R(n);
        vector<long long> val(n);
        vector<bool> active(n, true); // <--- CRITICAL FIX: Track if node is deleted

        // 2. Min-Heap: Stores {sum, left_index}
        // Ordered by Sum (asc), then Index (asc) for tie-breaking
        using Pair = pair<long long, int>;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        int inversionCount = 0;

        // Initialize structures
        for (int i = 0; i < n; ++i) {
            val[i] = nums[i];
            L[i] = i - 1;
            R[i] = (i == n - 1) ? -1 : i + 1; // -1 indicates end of list

            // Check sorted condition and fill heap
            if (i + 1 < n) {
                if (nums[i] > nums[i + 1]) inversionCount++;
                pq.push({(long long)nums[i] + nums[i + 1], i});
            }
        }

        int operations = 0;

        while (inversionCount > 0 && !pq.empty()) {
            auto [sum, u] = pq.top();
            pq.pop();

            // --- VALIDATION CHECKS ---
            // 1. Is 'u' still alive? (It might have been merged into its left neighbor)
            if (!active[u]) continue;

            int v = R[u];
            // 2. Does 'u' still have a right neighbor?
            if (v == -1) continue;

            // 3. Is the sum current? (Values might have changed due to other merges)
            if (val[u] + val[v] != sum) continue;


            // --- PERFORM MERGE (Merge v into u) ---
            operations++;
            
            // Step A: Remove OLD inversions involving u and v
            // 1. Internal pair (u, v)
            if (val[u] > val[v]) inversionCount--;
            // 2. Left boundary (L[u], u)
            if (L[u] != -1 && val[L[u]] > val[u]) inversionCount--;
            // 3. Right boundary (v, R[v])
            if (R[v] != -1 && val[v] > val[R[v]]) inversionCount--;

            // Step B: Update values and pointers
            val[u] = sum;          // u gets the new sum
            active[v] = false;     // v is effectively deleted <--- MARK DEAD
            
            int next_neighbor = R[v];
            R[u] = next_neighbor;  // u skips v to point to v's neighbor
            if (next_neighbor != -1) {
                L[next_neighbor] = u; // Neighbor points back to u
            }

            // Step C: Add NEW inversions
            // 1. Left boundary (L[u], new_u)
            if (L[u] != -1 && val[L[u]] > val[u]) inversionCount++;
            // 2. Right boundary (new_u, next_neighbor)
            if (next_neighbor != -1 && val[u] > val[next_neighbor]) inversionCount++;

            // Step D: Push new adjacent sums to Heap
            if (L[u] != -1) {
                pq.push({val[L[u]] + val[u], L[u]});
            }
            if (R[u] != -1) {
                pq.push({val[u] + val[R[u]], u});
            }
        }

        return operations;
    }
};