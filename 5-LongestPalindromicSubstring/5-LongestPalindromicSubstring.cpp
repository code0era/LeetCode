// Last updated: 1/16/2026, 8:22:22 PM
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;

        int start = 0, end = 0;

        // function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // length of palindrome
        };

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(i, i);       // odd length
            int len2 = expand(i, i + 1);   // even length
            int len = max(len1, len2);

            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
