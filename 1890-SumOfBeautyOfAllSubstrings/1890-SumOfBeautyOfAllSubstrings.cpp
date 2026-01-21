// Last updated: 1/21/2026, 3:20:33 PM
class Solution {
public:
    int beautySum(string s) {
        int total = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxF = 0, minF = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxF = max(maxF, freq[k]);
                        minF = min(minF, freq[k]);
                    }
                }
                total += (maxF - minF);
            }
        }
        return total;
    }
};