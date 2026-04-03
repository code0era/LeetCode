// Last updated: 4/3/2026, 7:59:10 AM
class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    vector<vector<int>> count(2, vector<int>(26));

    for (int i = 0; i < s1.length(); ++i) {
      ++count[i % 2][s1[i] - 'a'];
      --count[i % 2][s2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
      if (count[0][i] > 0 || count[1][i] > 0)
        return false;

    return true;
  }
};