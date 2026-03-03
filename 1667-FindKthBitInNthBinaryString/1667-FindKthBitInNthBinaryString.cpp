// Last updated: 3/4/2026, 4:51:39 AM
class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is always "0"
        if (n == 1) return '0';

        int length = (1 << n) - 1; // 2^n - 1
        int mid = length / 2 + 1;

        if (k == mid) {
            return '1';
        } else if (k < mid) {
            // k is in the left part, which is exactly S_{n-1}
            return findKthBit(n - 1, k);
        } else {
            // k is in the right part (reverse + invert of S_{n-1})
            // Find the mirrored position in the first half
            char bit = findKthBit(n - 1, length - k + 1);
            // Invert the bit
            return (bit == '0') ? '1' : '0';
        }
    }
};