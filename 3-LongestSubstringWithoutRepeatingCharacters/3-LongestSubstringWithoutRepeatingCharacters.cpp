// Last updated: 1/16/2026, 8:22:25 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // stores last seen index of each character
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            // If character seen before, shrink window
            if (last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right; // update last seen

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
