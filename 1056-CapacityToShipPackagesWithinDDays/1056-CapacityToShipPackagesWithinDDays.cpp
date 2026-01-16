// Last updated: 1/16/2026, 8:20:45 PM
class Solution {
public:

    int val (vector<int>& weights, int c){
        int cn = 1;
        int sum= 0;
        for(auto it: weights){
             if (sum + it > c) {
                cn++;          // new day
                sum = it;      // start with current weight
            } else {
                sum += it;
            }
        }
        return cn;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int mx = INT_MIN;
        for(auto it: weights){
            sum+=it;
            mx = max(mx , it);
        }
        int l = mx ;
        int h = sum;
        while(l <= h ){
            int mid = l+( h-l) /2;
            if(val(weights ,mid) <= days){
                h = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};