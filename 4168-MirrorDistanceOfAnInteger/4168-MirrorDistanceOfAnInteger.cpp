// Last updated: 1/16/2026, 8:19:36 PM
class Solution {
public:
    int mirrorDistance(int n) {
        int r = 0;
        int o = n ;
        while(n>0){
            r = r*10 + (n%10);
            n /=10;
            
        }
        return abs(o -r);
    }
};