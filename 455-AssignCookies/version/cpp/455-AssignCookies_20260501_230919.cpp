// Last updated: 5/1/2026, 11:09:19 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        int n = g.size();
5        int m = s.size(); 
6
7        sort(g.begin(), g.end());
8        sort(s.begin(), s.end());
9
10        int child = 0; 
11        int cookie = 0; 
12
13        while (child < n && cookie < m) {
14            if (s[cookie] >= g[child]) {
15                child++; // This child is now content, move to next child
16            }
17            cookie++;
18        }
19        
20        return child;
21    }
22};