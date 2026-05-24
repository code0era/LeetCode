// Last updated: 5/24/2026, 9:59:37 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            int min_v = min(a, b);
            int max_v = max(a, b);
            
            diff[min_v + 1] -= 1;
            diff[max_v + limit + 1] += 1;

            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int min_moves = n;
        int current_moves = 0;
        for (int s = 2; s <= 2 * limit; ++s) {
            current_moves += diff[s];
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};