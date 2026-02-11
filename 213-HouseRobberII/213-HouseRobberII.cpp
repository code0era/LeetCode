// Last updated: 2/11/2026, 8:20:54 PM
1class Solution {
2public:
3    int robLine(vector<int>& nums, int l, int r) {
4        int prev2 = 0, prev1 = 0;
5
6        for(int i = l; i <= r; i++) {
7            int take = nums[i] + prev2;
8            int skip = prev1;
9            int cur = max(take, skip);
10            prev2 = prev1;
11            prev1 = cur;
12        }
13        return prev1;
14    }
15
16    int rob(vector<int>& nums) {
17        int n = nums.size();
18        if(n == 1) return nums[0];
19
20        return max(
21            robLine(nums, 0, n-2),  // skip last
22            robLine(nums, 1, n-1)   // skip first
23        );
24    }
25};