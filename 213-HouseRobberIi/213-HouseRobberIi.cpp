// Last updated: 2/11/2026, 10:34:55 PM
class Solution {
public:
    int robLine(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;

        for(int i = l; i <= r; i++) {
            int take = nums[i] + prev2;
            int skip = prev1;
            int cur = max(take, skip);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(
            robLine(nums, 0, n-2),  // skip last
            robLine(nums, 1, n-1)   // skip first
        );
    }
};