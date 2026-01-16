// Last updated: 1/16/2026, 8:20:02 PM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<long long, long long> leftCount, rightCount;

        // Step 1: Fill rightCount with occurrences of all numbers
        for (int x : nums) rightCount[x]++;

        long long ans = 0;

        // Step 2: Iterate j from 0 to n-1
        for (int j = 0; j < nums.size(); j++) {
            long long val = nums[j];
            long long need = val * 2;

            // Current element moves from right to left
            rightCount[val]--;

            // Count valid i < j and k > j
            long long leftWays  = leftCount[need];
            long long rightWays = rightCount[need];

            ans = (ans + (leftWays * rightWays) % MOD) % MOD;

            // Mark nums[j] as now part of the left side
            leftCount[val]++;
        }

        return ans % MOD;
    }
};
