// Last updated: 3/16/2026, 11:10:38 PM
class Solution {
public:
    int countCommas(int n) {
         long long ans =0 ;
        if(n>=1000){
            ans +=(min(n, 999999)-999)*1;
        }
        if(n>= 1000000){
            ans+=(min(n , 999999999)-999999)*2;
            
        }
        if(n>= 1000000000){
            ans+=(n , 999999999)*3;
            
        }
        return ans;
    }
};