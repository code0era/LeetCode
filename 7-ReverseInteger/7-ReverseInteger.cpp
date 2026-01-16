// Last updated: 1/16/2026, 8:22:21 PM
class Solution {
public:
    long long reverse(long long  x) {
        // Extract number
        
        long long x1 = abs(x);
        long long rn= 0;
        while(x1 >0){
            int ld = x1%10;
            rn = rn*10 + ld;
            if(rn > INT_MAX || rn < INT_MIN){
                rn = 0;
            }
            x1/=10;
        }
        if(x<0){
            rn = -rn;
        }
        return  rn;

        
    }
};