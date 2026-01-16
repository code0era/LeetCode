// Last updated: 1/16/2026, 8:20:25 PM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0, total = 0;
        int res = 1;
        
        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            
            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                ++left;
            }
            
            res = max(res, (int)(right - left + 1)); // Cast to int here
        }
        
        return res;
    }
};
