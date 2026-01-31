// Last updated: 1/31/2026, 8:21:08 PM
/*
 * tc : O(n log max(nums))
 * sc : O(1);
*/

1class Solution {
2public:
3    int minimumK(vector<int>& nums) {
4        long long l =1 ,r = 1e5, n = nums.size();
5        while(l<r){
6            long long m = (l+r)/2,s =0;
7            for(int x : nums){
8                s+=(x+m-1)/m;
9                if(s>m*m)break;
10            }
11            if(s<=m*m) r = m ;
12            else l = m+1;
13        
14        }
15        return l;
16    }
17};