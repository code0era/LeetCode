// Last updated: 5/23/2026, 10:04:42 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 1e9;
        for( int x= 0 ; x<k ; x++){
            for( int y  = 0 ; y< k ; y++){
                if( x==y) continue;
                int cur = 0;
                for( int i =0; i< nums.size(); i++){
                    int t = (i % 2 ? y: x);
                    int r = nums[i] % k ;
                     cur += min((r-t+k)%k,  (t-r+k)%k);
                }
                ans = min( ans , cur);
            }
        }
        return ans;
    }
};