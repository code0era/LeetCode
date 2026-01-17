// Last updated: 1/17/2026, 6:54:52 PM
class Solution {
public:
string encode(string s) {
    unordered_map<char, int> mp;
    string res;
    int id = 0;

    for (char c : s) {
        if (!mp.count(c)) {
            mp[c] = id++;
        }
        res += char(mp[c] + 'a');  // single char instead of number+comma
    }
    return res;
}

    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
};