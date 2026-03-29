// Last updated: 3/29/2026, 9:05:29 AM
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string a = {s1[0], s1[2]};
        string b = {s1[1], s1[3]};
        string c = {s2[0], s2[2]};
        string d = {s2[1], s2[3]};

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        return a == c && b == d;
    }
};