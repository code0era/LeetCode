// Last updated: 2/5/2026, 9:02:09 PM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};