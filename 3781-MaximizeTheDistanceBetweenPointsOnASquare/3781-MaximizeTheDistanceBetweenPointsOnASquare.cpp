// Last updated: 5/1/2026, 4:43:45 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> d;
        // 1. Map 2D points to 1D positions along the perimeter [0, 4*side)
        for (auto& p : points) {
            if (p[1] == 0) d.push_back(p[0]); // Bottom
            else if (p[0] == side) d.push_back(side + p[1]); // Right
            else if (p[1] == side) d.push_back(2LL * side + (side - p[0])); // Top
            else d.push_back(3LL * side + (side - p[1])); // Left
        }
        sort(d.begin(), d.end());
        int n = d.size();
        // 2. Double the array to handle the circular wrap-around easily
        for (int i = 0; i < n; ++i) d.push_back(d[i] + 4LL * side);

        // 3. Binary search for the maximum possible minimum distance 'mid'
        long long low = 0, high = side, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, d, n, k, 4LL * side)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return (int)ans;
    }

private:
    bool check(long long dist, const vector<long long>& d, int n, int k, long long mod) {
        // Greedy: Try starting the sequence from each of the first 'n' points
        for (int i = 0; i < n; ++i) {
            int count = 1;
            long long last = d[i];
            int curr = i;
            for (int j = 1; j < k; ++j) {
                // Find next point at least 'dist' away
                auto it = lower_bound(d.begin() + curr + 1, d.begin() + i + n, last + dist);
                if (it == d.begin() + i + n) { count = -1; break; } 
                last = *it;
                curr = distance(d.begin(), it);
                count++;
            }
            // Ensure the last point and the first point also respect the 'dist' (circularity)
            if (count == k && (d[i] + mod - last) >= dist) return true;
        }
        return false;
    }
};