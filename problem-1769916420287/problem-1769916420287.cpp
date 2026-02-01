// Last updated: 2/1/2026, 8:57:00 AM
1class Solution {
2public:
3    int countMonobit(int n) {
4        int c  = 1 ;
5        long long cr =1;
6        while(cr<=n){
7            c++;
8            cr = (cr<<1)|1;
9            
10        }
11        return c ;
12    }
13};