// Last updated: 6/14/2026, 9:34:57 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return 1LL * k * (mx - mn);
    }
};