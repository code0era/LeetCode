// Last updated: 1/16/2026, 8:21:22 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[m + 1]) {
                // peak is on the left side (including m)
                r = m;
            } else {
                // peak is on the right side
                l = m + 1;
            }
        }
        return l; // or r (both same)
    }
};
