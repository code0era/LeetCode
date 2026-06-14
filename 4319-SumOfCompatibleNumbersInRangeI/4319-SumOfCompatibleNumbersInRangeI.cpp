// Last updated: 6/14/2026, 9:33:49 AM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int x = 1 ; x <=n+k; ++x){
            if(abs(n-x)<=k&&(n&x)==0){
                sum+=x;
            }
        }
        return sum;
    }
};