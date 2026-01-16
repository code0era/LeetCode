// Last updated: 1/16/2026, 8:20:18 PM
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int score = 0;
        int minScore = 0;
        int bestHour = 0;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                score--;
            } else {
                score++;
            }

            if (score < minScore) {
                minScore = score;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};