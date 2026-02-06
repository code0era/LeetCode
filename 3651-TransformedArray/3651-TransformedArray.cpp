// Last updated: 2/6/2026, 5:17:52 PM
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            // If nums[i] is 0, we stay at the same index
            if (nums[i] == 0) {
                result[i] = nums[i];
            } else {
                // Calculate circular index
                // (i + nums[i]) could be negative, so we use the circular formula
                int targetIndex = (i + nums[i] % n + n) % n;
                result[i] = nums[targetIndex];
            }
        }

        return result;
    }
};