// Last updated: 2/6/2026, 5:17:40 PM
#include <vector>

class Solution {
public:
    bool isTrionic(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i == 0) return false;

        int j = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        if (i == j || i == n - 1) return false;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};