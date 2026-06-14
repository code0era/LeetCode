// Last updated: 6/14/2026, 9:33:47 AM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int a = 0, b= 0 ;
        while(n){
            int d = n%10;
            a+=d;
            b+= d*d;
            n/=10;
            
        }
        return b-a>=50;
    }
};