// Last updated: 3/4/2026, 4:51:37 AM
#include <vector>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> trailingZeros(n, 0);

        // 1. Preprocess: Count trailing zeros for each row
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros[i] = count;
        }

        int totalSwaps = 0;

        // 2. Greedy Swapping
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i; // Required zeros for row i
            int foundIdx = -1;

            // Find the first row that satisfies the condition
            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= target) {
                    foundIdx = j;
                    break;
                }
            }

            if (foundIdx == -1) return -1; // Impossible to satisfy

            // Swap rows greedily (simulate adjacent swaps)
            for (int k = foundIdx; k > i; --k) {
                std::swap(trailingZeros[k], trailingZeros[k - 1]);
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
};