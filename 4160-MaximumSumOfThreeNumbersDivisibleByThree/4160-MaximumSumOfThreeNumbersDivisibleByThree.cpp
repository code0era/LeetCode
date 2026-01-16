// Last updated: 1/16/2026, 8:19:43 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> v = nums; 
        vector<int> a, b, c;

        for (int x : v) {
            if (x % 3 == 0) a.push_back(x);
            else if (x % 3 == 1) b.push_back(x);
            else c.push_back(x);
        }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        long long m = 0;

        if (a.size() >= 3) {
            m = max(m, (long long)a[0] + a[1] + a[2]);
        }
        if (b.size() >= 3) {
            m = max(m, (long long)b[0] + b[1] + b[2]);
        }
        if (c.size() >= 3) {
            m = max(m, (long long)c[0] + c[1] + c[2]);
        }
        if (!a.empty() && !b.empty() && !c.empty()) {
            m = max(m, (long long)a[0] + b[0] + c[0]);
        }

        return (int)m;
    }
};