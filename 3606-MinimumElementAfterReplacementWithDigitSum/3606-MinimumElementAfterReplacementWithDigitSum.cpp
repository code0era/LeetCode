// Last updated: 6/14/2026, 9:35:56 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (int x : nums) {
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};