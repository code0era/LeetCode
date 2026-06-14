// Last updated: 6/14/2026, 9:38:04 AM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();

        while (i < n - 1) {
            if (bits[i] == 1)
                i += 2;  // skip next bit
            else
                i += 1;
        }

        return i == n - 1;
    }
};