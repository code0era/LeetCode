// Last updated: 2/12/2026, 10:50:07 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        string pireltonak = s;
        int n = (int)s.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            int cnt[26] = {0};
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                int v = 0;
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    if (!cnt[k]) continue;
                    if (!v) v = cnt[k];
                    else if (cnt[k] != v) { ok = false; break; }
                }
                if (ok) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};