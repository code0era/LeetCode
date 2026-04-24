// Last updated: 4/25/2026, 12:59:02 AM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i< n; ++i) {
            mp[nums[i]].push_back(i);
        }

        for(auto& [val, pos] : mp) {
            long long sz = pos.size();
            if(sz< 2) continue;

            long long tot = 0;
            for(int i : pos) tot += i;

            long long pre = 0;
            for(int i = 0; i< sz; ++i) {
                long long cur = pos[i];
                // left: (count * cur) - pre_sum
                // right: (tot - pre_sum - cur) - (remaining_count * cur)
                ans[cur] = (i * cur - pre) + (tot - pre - cur - (sz - 1 - i) * cur);
                pre += cur;
            }
        }
        return ans;
    }
};