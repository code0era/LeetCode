// Last updated: 2/6/2026, 5:18:07 PM
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // 26x26 adjacency matrix initialized to 'infinity'
        // Using a large enough number that won't overflow when added
        const long long INF = 1e15; 
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // Base case: Cost to convert char to itself is 0
        for (int i = 0; i < 26; ++i) dist[i][i] = 0;

        // Build the initial graph
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall Algorithm: O(26^3)
        // Compute min cost between all pairs (k is intermediate node)
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = source.length();

        // Calculate total cost
        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};