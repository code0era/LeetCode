// Last updated: 6/14/2026, 9:37:45 AM
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int diff = (accumulate(aliceSizes.begin(), aliceSizes.end(), 0) - accumulate(bobSizes.begin(), bobSizes.end(), 0)) / 2;
        unordered_set<int> s(aliceSizes.begin(), aliceSizes.end());
        for (int b : bobSizes)
            if (s.count(b + diff)) return {b + diff, b};
        return {};
    }
};