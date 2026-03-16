// Last updated: 3/16/2026, 11:10:41 PM
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long  i = 1000, c =1; i <=n; i*=1000, c++){
            ans+= (min(n, i*1000 -1) - i +1)*c;
            
        }
        return ans;
    }
};