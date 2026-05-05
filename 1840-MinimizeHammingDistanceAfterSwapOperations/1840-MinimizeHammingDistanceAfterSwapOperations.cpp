// Last updated: 5/5/2026, 9:13:45 PM
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), res = 0;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int i) {
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        };
        for (auto& s : allowedSwaps) {
            int root1 = find(s[0]), root2 = find(s[1]);
            if (root1 != root2) parent[root1] = root2;
        }
        unordered_map<int, unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++) groups[find(i)][source[i]]++;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (groups[root][target[i]] > 0) groups[root][target[i]]--;
            else res++;
        }
        return res;
    }
};