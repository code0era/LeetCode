// Last updated: 1/17/2026, 6:54:56 PM
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size()-1;
        while (i >= 0) {
            while (i >=0 && s[i] == ' ')i--;
            if (i < 0)
                break;

            int j = i;

            // jsut find aa word from back and measuring the length
            while (j >= 0 && s[j] != ' ')
                j--;
            if (!ans.empty())
                ans += " ";
            ans += s.substr(j + 1, i - j);
            i = j - 1;
        }
        return ans;
    }
};