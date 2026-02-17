// Last updated: 2/17/2026, 11:21:48 PM
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};