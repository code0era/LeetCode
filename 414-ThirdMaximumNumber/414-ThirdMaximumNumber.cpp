// Last updated: 3/4/2026, 4:52:14 AM
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long f = LONG_MIN;
        long s = LONG_MIN;
        long t = LONG_MIN;
        for(int num: nums){
            if(num == f || num == s || num == t)  continue;
            if(num> f){
                t =s;
                s = f;
                f = num;
            }
            else if(num>s) {
                t = s;
                s = num;
            }else if (num>t){
                t = num;
            }
        }
        return (t ==LONG_MIN)?  f: t;
    }
};