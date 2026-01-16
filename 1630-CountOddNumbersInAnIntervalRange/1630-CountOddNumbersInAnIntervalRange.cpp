// Last updated: 1/16/2026, 8:20:27 PM
class Solution {
public:
    int countOdds(int low, int high) {
        int total = (high - low) / 2;
        if (low % 2 == 1 || high % 2 == 1) total++;
        return total;
    }
};
