// Last updated: 5/15/2026, 8:34:35 PM
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        int base = n - 1;
        vector<int> count(n, 0);

        for (int x : nums) {
            if (x > base || x < 1) return false;
            count[x]++;
        }

        for (int i = 1; i < base; ++i) {
            if (count[i] != 1) return false;
        }

        return count[base] == 2;
    }
};