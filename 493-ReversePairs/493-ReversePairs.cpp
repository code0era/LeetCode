// Last updated: 3/4/2026, 4:52:12 AM
class Solution {
public:
    long long ans = 0;

    void mergeCount(vector<int>& a, int l, int m, int r) {
        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)a[i] > 2LL * (long long)a[j]) j++;
            ans += (j - (m + 1));
        }

        vector<int> tmp;
        tmp.reserve(r - l + 1);
        int i = l; 
        j = m + 1;

        while (i <= m && j <= r) {
            if (a[i] <= a[j]) tmp.push_back(a[i++]);
            else tmp.push_back(a[j++]);
        }
        while (i <= m) tmp.push_back(a[i++]);
        while (j <= r) tmp.push_back(a[j++]);

        for (int k = 0; k < (int)tmp.size(); k++) a[l + k] = tmp[k];
    }

    void sortSolve(vector<int>& a, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        sortSolve(a, l, m);
        sortSolve(a, m + 1, r);
        mergeCount(a, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        if (!nums.empty()) sortSolve(nums, 0, (int)nums.size() - 1);
        return (int)ans;
    }
};