// Last updated: 2/26/2026, 9:09:08 PM
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int bal = 0, start = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            bal += (s[i] == '1') ? 1 : -1;
            if (bal == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }
        sort(parts.begin(), parts.end(), greater<string>());
        string res;
        for (auto &p : parts) res += p;
        return res;
    }
};