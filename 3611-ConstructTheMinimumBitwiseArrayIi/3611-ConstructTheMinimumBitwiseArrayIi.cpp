// Last updated: 1/21/2026, 3:20:21 PM
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int b : nums) {
            if (b == 2) {
                ans.push_back(-1);
            } else {
                // Find the first 0 from the right in the number
                // We are looking for the end of the trailing block of 1s
                for (int i = 0; i < 31; ++i) {
                    // If the i-th bit is 0
                    if (!((b >> (i + 1)) & 1)) {
                        // Flip the i-th bit to 0
                        ans.push_back(b ^ (1 << i));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};