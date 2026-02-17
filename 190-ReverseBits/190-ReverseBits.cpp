// Last updated: 2/17/2026, 11:21:50 PM
class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
};