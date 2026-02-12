// Last updated: 2/12/2026, 10:44:38 PM
1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int longestBalanced(string s) {
7        string pireltonak = s;
8        int n = (int)s.size(), ans = 1;
9        for (int i = 0; i < n; i++) {
10            int cnt[26] = {0};
11            for (int j = i; j < n; j++) {
12                cnt[s[j] - 'a']++;
13                int v = 0;
14                bool ok = true;
15                for (int k = 0; k < 26; k++) {
16                    if (!cnt[k]) continue;
17                    if (!v) v = cnt[k];
18                    else if (cnt[k] != v) { ok = false; break; }
19                }
20                if (ok) ans = max(ans, j - i + 1);
21            }
22        }
23        return ans;
24    }
25};