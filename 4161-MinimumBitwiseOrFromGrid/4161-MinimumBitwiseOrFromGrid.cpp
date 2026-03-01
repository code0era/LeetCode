// Last updated: 3/1/2026, 9:34:04 AM
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOR(vector<vector<int>>& g) {
        int res = 0;
        for (int b = 17; b >= 0; --b) {
            int mask = res | ((1 << b) - 1);
            bool ok = true;
            for (const auto& r : g) {
                bool found = false;
                for (int v : r) {
                    if ((v | mask) == mask) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ok = false;
                    break;
                }
            }
            if (!ok) res |= (1 << b);
        }
        return res;
    }
};