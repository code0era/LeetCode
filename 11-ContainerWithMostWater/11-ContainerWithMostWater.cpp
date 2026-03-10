// Last updated: 3/10/2026, 10:26:07 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        long long best = 0;

        while (l < r) {
            long long width = r - l;
            long long h = min(height[l], height[r]);
            best = max(best, width * h);

            if (height[l] <= height[r]) l++;
            else r--;
        }
        return (int)best;
    }
};