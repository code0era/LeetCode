// Last updated: 1/16/2026, 8:20:21 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // 1. Sort events based on start time
        sort(events.begin(), events.end());
        
        // 2. Create a suffix maximum array to store the max value from index i to n-1
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }
        
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            // Option 1: Just take the current event
            maxSum = max(maxSum, events[i][2]);
            
            // Option 2: Find the next non-overlapping event using binary search
            // We need an event where nextEvent.startTime > currentEvent.endTime
            int endTime = events[i][1];
            
            // Use binary search to find the first event with startTime > endTime
            auto it = upper_bound(events.begin() + i + 1, events.end(), endTime, 
                [](int val, const vector<int>& e) {
                    return val < e[0];
                });
            
            if (it != events.end()) {
                int nextIdx = distance(events.begin(), it);
                maxSum = max(maxSum, events[i][2] + suffixMax[nextIdx]);
            }
        }
        
        return maxSum;
    }
};