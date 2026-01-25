// Last updated: 1/25/2026, 1:09:06 PM
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        // If we only need to pick 1 score, the difference is always 0
        if (k == 1) return 0;

        // Step 1: Sort the scores
        std::sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Step 2: Use a sliding window of size k
        // The window ends at 'i' and starts at 'i - k + 1'
        for (int i = k - 1; i < nums.size(); ++i) {
            int currentDiff = nums[i] - nums[i - k + 1];
            
            // Step 3: Update the minimum difference found so far
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
            }
        }

        return minDiff;
    }
};