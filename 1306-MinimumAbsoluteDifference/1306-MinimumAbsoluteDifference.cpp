// Last updated: 1/26/2026, 3:22:48 PM
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        // Step 1: Sort the array to ensure adjacent elements have the smallest differences
        std::sort(arr.begin(), arr.end());
        
        std::vector<std::vector<int>> result;
        int min_diff = INT_MAX;
        
        // Step 2: Iterate through the sorted array
        for (int i = 0; i < arr.size() - 1; ++i) {
            int current_diff = arr[i+1] - arr[i];
            
            // Case A: Found a new smaller difference
            if (current_diff < min_diff) {
                min_diff = current_diff;
                result.clear(); // Discard previous pairs, they are not the minimum anymore
                result.push_back({arr[i], arr[i+1]});
            }
            // Case B: Found a difference equal to the current minimum
            else if (current_diff == min_diff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        
        return result;
    }
};