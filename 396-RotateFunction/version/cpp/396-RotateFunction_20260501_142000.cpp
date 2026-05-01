// Last updated: 5/1/2026, 2:20:00 PM
1class Solution {
2 public:
3  int maxRotateFunction(vector<int>& nums) {
4    const int sum = accumulate(nums.begin(), nums.end(), 0);
5    int f = 0;
6
7    // Calculate F(0) first.
8    for(int i = 0; i < nums.size(); ++i)
9      f += i * nums[i];
10
11    int ans = f;
12
13    for(int i = nums.size() - 1; i > 0; --i) {
14      f += sum - nums.size() * nums[i];
15      ans = max(ans, f);
16    }
17
18    return ans;
19  }
20};
21
22
23