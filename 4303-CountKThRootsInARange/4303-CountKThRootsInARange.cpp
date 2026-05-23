// Last updated: 5/23/2026, 10:04:49 PM
#include<cmath>


class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if ( k == 1) return r-l +1;
        int low = round(pow(l , 1.0/k));
        int high = round(pow(r , 1.0/k));
        if (pow(low , k )<l) low++;
        if (pow(high , k )>r) high--;
        return ( high>=low)?(high -low+1): 0;
    }
};