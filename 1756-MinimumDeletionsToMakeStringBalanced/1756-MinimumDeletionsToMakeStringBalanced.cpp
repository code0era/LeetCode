// Last updated: 2/7/2026, 8:01:29 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;    
        int del = 0;   

        for (char c : s) {
            if (c == 'b') {
                b++;
            } else { // c == 'a'
         
                del = min(del + 1, b);
            }
        }
        return del;
    }
};