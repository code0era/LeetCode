// Last updated: 2/6/2026, 5:17:37 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int best = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (l <= r && 1LL * nums[l] * k < nums[r]) ++l;
            best = max(best, r - l + 1);
        }
        return n - best;
    }
};