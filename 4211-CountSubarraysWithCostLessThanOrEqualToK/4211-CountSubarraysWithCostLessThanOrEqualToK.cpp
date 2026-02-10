// Last updated: 2/11/2026, 12:52:46 AM
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), l = 0, ans = 0;
        deque<int> mx, mi; // Stores indices for max and min elements

        for (int r = 0; r < n; ++r) {
            // Maintain monotonic deques
            while (!mx.empty() && nums[mx.back()] <= nums[r]) mx.pop_back();
            while (!mi.empty() && nums[mi.back()] >= nums[r]) mi.pop_back();
            mx.push_back(r);
            mi.push_back(r);

            // Shrink window if cost > k
            while (l <= r && (long long)(nums[mx.front()] - nums[mi.front()]) * (r - l + 1) > k) {
                if (mx.front() == l) mx.pop_front();
                if (mi.front() == l) mi.pop_front();
                l++;
            }
            // All subarrays ending at r and starting from [l...r] are valid
            ans += (r - l + 1);
        }
        return ans;
    }
};