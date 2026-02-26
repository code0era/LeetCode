// Last updated: 2/26/2026, 9:08:47 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortByBits(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // Primary sort: bit count
            if (countA != countB) {
                return countA < countB;
            }
            // Secondary sort (tie-breaker): numerical value
            return a < b;
        });
        
        return arr;
    }
};