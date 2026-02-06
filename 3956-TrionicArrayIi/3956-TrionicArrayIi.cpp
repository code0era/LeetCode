// Last updated: 2/6/2026, 5:17:39 PM
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG = -500000000000000LL;
        int n = (int)nums.size();

        auto add = [&](long long v, long long x) -> long long {
            return (v == NEG) ? NEG : v + x;
        };

        long long dp0 = nums[0], dp1 = NEG, dp2 = NEG, dp3 = NEG;
        long long ans = NEG;

        for (int i = 1; i < n; i++) {
            long long ndp0 = nums[i], ndp1 = NEG, ndp2 = NEG, ndp3 = NEG;

            if (nums[i] > nums[i - 1]) {
                ndp0 = max(ndp0, dp0 + nums[i]);
                ndp1 = max(ndp1, dp0 + nums[i]);
                ndp1 = max(ndp1, add(dp1, nums[i]));
                ndp3 = max(ndp3, add(dp2, nums[i]));
                ndp3 = max(ndp3, add(dp3, nums[i]));
            }

            if (nums[i] < nums[i - 1]) {
                ndp2 = max(ndp2, add(dp1, nums[i]));
                ndp2 = max(ndp2, add(dp2, nums[i]));
            }

            dp0 = ndp0; dp1 = ndp1; dp2 = ndp2; dp3 = ndp3;
            ans = max(ans, dp3);
        }

        return ans;
    }
};
