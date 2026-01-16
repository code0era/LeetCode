// Last updated: 1/16/2026, 8:20:12 PM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) totalApples += a;

        // Sort capacities in descending order
        sort(capacity.rbegin(), capacity.rend());

        int sum = 0, count = 0;
        for (int cap : capacity) {
            sum += cap;
            count++;
            if (sum >= totalApples) break;
        }

        return count;
    }
};
