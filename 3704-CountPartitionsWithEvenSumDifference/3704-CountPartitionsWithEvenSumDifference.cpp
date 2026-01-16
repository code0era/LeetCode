// Last updated: 1/16/2026, 8:20:10 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int leftSum = 0;
        int count = 0;

        // Loop until the second last element
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            if ((2 * leftSum - totalSum) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};
