// Last updated: 3/10/2026, 10:23:56 PM

class Solution {
public:
    bool checkOnesSegment(string s) {
        // find() returns string::npos if the substring is not found
        return s.find("01") == string::npos;
    }
};