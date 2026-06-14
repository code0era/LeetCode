// Last updated: 6/14/2026, 9:36:17 AM
#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int leftSum = 0;
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            rightSum -= nums[i];
            ans[i] = std::abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return ans;
    }
};
