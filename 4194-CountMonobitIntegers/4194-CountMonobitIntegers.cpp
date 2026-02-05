// Last updated: 2/5/2026, 9:01:39 PM
class Solution {
public:
    int countMonobit(int n) {
        int c  = 1 ;
        long long cr =1;
        while(cr<=n){
            c++;
            cr = (cr<<1)|1;
            
        }
        return c ;
    }
};