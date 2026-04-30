// Last updated: 5/1/2026, 4:43:36 AM
#include <vector>
#include <numeric>

class Solution {
public:
    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        // Process each query
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            // Increment by k to follow the step-based multiplication
            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        // Calculate final XOR sum
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};
