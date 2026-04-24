// Last updated: 4/25/2026, 12:58:59 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, countUnder = 0;
        
        for (char c : moves) {
            if (c == 'L') countL++;
            else if (c == 'R') countR++;
            else countUnder++;
        }
        
        return abs(countL - countR) + countUnder;
    }
};