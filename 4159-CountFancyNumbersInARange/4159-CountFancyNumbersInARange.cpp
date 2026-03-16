// Last updated: 3/16/2026, 11:11:02 PM
class Solution {
    long long memo[17][150][11][5][2][2];
    bool is_good_cache[150];

    bool checkMonotone(int n) {
        if (n < 10) return true;
        string s = to_string(n);
        bool inc = true, dec = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] <= s[i-1]) inc = false;
            if (s[i] >= s[i-1]) dec = false;
        }
        return inc || dec;
    }

    long long dp(int idx, int sum, int last, int type, bool is_less, bool is_started, const string& s) {
        if (idx == s.size()) {
            if (!is_started) return 0;
            return (type >= 1 && type <= 3) || is_good_cache[sum];
        }
        if (memo[idx][sum][last][type][is_less][is_started] != -1)
            return memo[idx][sum][last][type][is_less][is_started];

        long long ans = 0;
        int limit = is_less ? 9 : s[idx] - '0';

        for (int d = 0; d <= limit; d++) {
            bool n_less = is_less || (d < limit);
            bool n_started = is_started || (d > 0);
            int n_type = type;

            if (!n_started) {
                n_type = 0;
            } else if (!is_started && d > 0) {
                n_type = 3; 
            } else if (is_started) {
                if (type == 3) {
                    if (d > last) n_type = 1;     
                    else if (d < last) n_type = 2; 
                    else n_type = 4;              
                } else if (type == 1) {
                    if (d <= last) n_type = 4;     
                } else if (type == 2) {
                    if (d >= last) n_type = 4;    
                }
            }

            ans += dp(idx + 1, sum + d, d, n_type, n_less, n_started, s);
        }
        return memo[idx][sum][last][type][is_less][is_started] = ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;
        string s = to_string(n);
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 10, 0, false, false, s);
    }

public:
    long long countFancy(long long l, long long r) {
        for (int i = 0; i < 150; i++) is_good_cache[i] = checkMonotone(i);
        return solve(r) - solve(l - 1);
    }
};