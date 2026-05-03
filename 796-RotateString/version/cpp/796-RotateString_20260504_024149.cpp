// Last updated: 5/4/2026, 2:41:49 AM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4
5        if (s.length() != goal.length()) {
6            return false;
7        }
8        
9        string doubled = s + s; 
10       
11        return doubled.find(goal) != string::npos;
12    }
13};