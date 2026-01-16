// Last updated: 1/16/2026, 8:20:40 PM
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            int c = 0;
            int s = 0;
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) { // divisor of x
                    c++;
                    s += i;
                    if (i != x / i) { // complementry of i : x/i
                        c++;
                        s += x / i;
                    }
                }
                if (c > 4)
                    break;
            }
            if (c == 4)ans += s;
        }
        return ans;
    }
};