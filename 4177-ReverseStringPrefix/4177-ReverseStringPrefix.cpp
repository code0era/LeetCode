// Last updated: 1/16/2026, 8:19:40 PM
class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin()+k);
        return s;
    }
};