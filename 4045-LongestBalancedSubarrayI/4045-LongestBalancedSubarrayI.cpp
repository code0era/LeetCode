// Last updated: 2/11/2026, 12:53:06 AM
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;

            for (int j = i; j < n; ++j) {
                // Classify the current number
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }

                // Check if the current subarray [i...j] is balanced
                if (distinctEvens.size() == distinctOdds.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};