// Last updated: 1/16/2026, 8:20:08 PM
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double minY = 1e9, maxY = -1e9;
        
        // Initial pass to calculate total area and the y-range
        for (const auto& s : squares) {
            double x = s[0], y = s[1], l = s[2];
            totalArea += l * l;
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }
        
        double low = minY, high = maxY;
        // Perform binary search for 100 iterations to ensure 10^-5 precision
        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2;
            if (getAreaBelow(squares, mid) < totalArea / 2.0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return low;
    }

private:
    double getAreaBelow(const vector<vector<int>>& squares, double k) {
        double area = 0;
        for (const auto& s : squares) {
            double y = s[1], l = s[2];
            if (k <= y) {
                continue; // Line is below the square
            } else if (k >= y + l) {
                area += l * l; // Square is entirely below the line
            } else {
                area += l * (k - y); // Line intersects the square
            }
        }
        return area;
    }
};