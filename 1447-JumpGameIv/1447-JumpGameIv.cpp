// Last updated: 5/24/2026, 9:59:57 AM
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), steps = 0;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; i++) g[arr[i]].push_back(i);
        
        queue<int> q({0});
        vector<bool> v(n, false);
        v[0] = true;

        while (!q.empty()) {
            for (int size = q.size(); size--; ) {
                int i = q.front(); q.pop();
                if (i == n - 1) return steps;
                
                vector<int>& next = g[arr[i]];
                next.push_back(i + 1);
                next.push_back(i - 1);
                
                for (int j : next) {
                    if (j >= 0 && j < n && !v[j]) {
                        v[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            steps++;
        }
        return 0;
    }
};