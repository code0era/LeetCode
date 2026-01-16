// Last updated: 1/16/2026, 8:22:10 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id = -1;
        int s = nums.size();
        for (int i = s - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = s - 1; i > id; i--) {
            if (nums[i] > nums[id]) {
                swap(nums[i], nums[id]);
                break;
            }
        }
        reverse(nums.begin() + id + 1, nums.end());
    }
};