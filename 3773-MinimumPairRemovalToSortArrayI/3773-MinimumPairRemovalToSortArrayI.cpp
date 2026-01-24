// Last updated: 1/24/2026, 5:50:10 AM

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        // Helper to check non-decreasing
        auto isSorted = [&](const vector<int>& arr) {
            for (int i = 1; i < (int)arr.size(); i++) {
                if (arr[i] < arr[i - 1])
                    return false;
            }
            return true;
        };

        // Keep merging until array is non-decreasing
        while (!isSorted(nums)) {
            int bestIndex = 0;
            int bestSum = nums[0] + nums[1];

            // Find adjacent pair with minimum sum
            for (int i = 1; i < (int)nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < bestSum) {
                    bestSum = sum;
                    bestIndex = i;
                }
            }

            // Replace pair with their sum
            nums[bestIndex] = bestSum;
            nums.erase(nums.begin() + bestIndex + 1);

            operations++;
        }

        return operations;
    }
};
