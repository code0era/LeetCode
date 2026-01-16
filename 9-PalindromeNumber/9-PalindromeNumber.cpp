// Last updated: 1/16/2026, 8:22:19 PM
class Solution {
public:
    bool isPalindrome(int x) {
        int  n = x;
        long long rn= 0;
        while(x>0){
            int ld = x%10;
            rn = rn*10 + ld;
            if(rn > INT_MAX || rn < INT_MIN){
                rn = 0;
            }
            x/=10;
        }
        if(n == rn){

        return true;
        }
        else return false;;

    }
};