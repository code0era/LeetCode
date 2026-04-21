// Last updated: 4/22/2026, 12:49:53 AM
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        long long min_dist = LLONG_MAX;
        bool found = false;
        for (auto& entry : pos) {
            vector<int>& indices = entry.second;
            if (indices.size() >= 3) {
                found = true;
                for (int i = 0; i < (int)indices.size() - 2; ++i) {
                    long long current_dist = 2LL * (indices[i + 2] - indices[i]);
                    if (current_dist < min_dist) {
                        min_dist = current_dist;
                    }
                }
            }
        }
        return found ? (int)min_dist : -1;
    }
};
