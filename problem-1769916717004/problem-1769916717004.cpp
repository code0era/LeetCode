// Last updated: 2/1/2026, 9:01:57 AM
1class Solution {
2public:
3    int finalElement(vector<int>& nums) {
4        return max(nums.front(), nums.back());
5    }
6};