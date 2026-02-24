// Last updated: 2/25/2026, 3:03:50 AM
class Solution {
public:
    int binaryGap(int n) {
        int last = -1, i = 0, ans = 0;
        while(n){
            if(n & 1){
                if(last != -1) ans = max(ans, i - last);
                last = i;
            }
            n >>= 1;
            i++;
        }
        return ans;
    }
};