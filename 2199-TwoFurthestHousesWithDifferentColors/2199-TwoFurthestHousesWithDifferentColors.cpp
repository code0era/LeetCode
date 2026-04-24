// Last updated: 4/25/2026, 12:59:10 AM
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Strategy 1: Compare everything against the first house (left end)
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                maxDist = std::max(maxDist, i);
                break;
            }
        }

        // Strategy 2: Compare everything against the last house (right end)
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxDist = std::max(maxDist, (n - 1) - i);
                break;
            }
        }

        return maxDist;
    }
};