// Last updated: 2/24/2026, 10:56:44 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0;
        int empty = 0;

        while (numBottles > 0) {
            drank += numBottles;
            empty += numBottles;

            numBottles = empty / numExchange;  // new full bottles
            empty = empty % numExchange;        // remaining empties
        }

        return drank;
    }
};