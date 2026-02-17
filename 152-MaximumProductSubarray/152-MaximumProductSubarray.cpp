// Last updated: 2/17/2026, 11:22:01 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mx = nums[0], mn = nums[0], ans = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            long long x = nums[i];

            if (x < 0) swap(mx, mn);

            mx = max(x, mx * x);
            mn = min(x, mn * x);

            ans = max(ans, mx);
        }
        return (int)ans;
    }
};