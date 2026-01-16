// Last updated: 1/16/2026, 8:19:49 PM
class Solution {
public:
    bool p(long long x) {
        if (x < 2) return false;
        for (long long i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.length();

        // check all prefixes
        for (int i = 1; i <= n; i++)
            if (!p(stoll(s.substr(0, i))))
                return false;

        // check all suffixes
        for (int i = 0; i < n; i++)
            if (!p(stoll(s.substr(i))))
                return false;

        return true;
    }
};
