// Last updated: 1/27/2026, 12:09:32 PM
1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int minCost(int n, vector<vector<int>>& edges) {
7        vector<vector<pair<int,int>>> g(n);
8        g.reserve(n);
9
10        for (auto &e : edges) {
11            int u = e[0], v = e[1], w = e[2];
12            g[u].push_back({v, w});       // normal direction
13            g[v].push_back({u, 2 * w});   // "use switch at v" to reverse v<-u, move v->u
14        }
15
16        const long long INF = (1LL<<62);
17        vector<long long> dist(n, INF);
18        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
19
20        dist[0] = 0;
21        pq.push({0, 0});
22
23        while (!pq.empty()) {
24            auto [d, u] = pq.top(); pq.pop();
25            if (d != dist[u]) continue;
26            if (u == n - 1) return (int)d;
27
28            for (auto [v, w] : g[u]) {
29                long long nd = d + w;
30                if (nd < dist[v]) {
31                    dist[v] = nd;
32                    pq.push({nd, v});
33                }
34            }
35        }
36        return -1;
37    }
38};
39