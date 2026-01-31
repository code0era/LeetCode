// Last updated: 1/31/2026, 8:15:45 PM
1class Solution {
2public:
3    string reverseByType(string s) {
4        string a, b ; 
5         for(char  c : s )((c>='a' && c <='z')? a : b ).push_back(c);
6        reverse(a.begin(), a.end());
7        reverse(b.begin(), b.end());
8        int i = 0 , j = 0 ;
9        for(char &c :s  ){
10            if(c>='a' && c <= 'z') c= a[i++];
11            else c = b[j++];
12        }
13        return s ;
14    }
15};