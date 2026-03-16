// Last updated: 3/16/2026, 11:10:44 PM
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>  prefixg(n);
        int  cm = 0;
        for( int i = 0 ; i < n ; i++){
            cm = max(cm , nums[i]);
            prefixg[i] = gcd(nums[i], cm);
        }
        sort(prefixg.begin()  , prefixg.end());
        long long ts = 0 ;
        int l = 0 , r = n-1;
         while(l<r){
             ts += gcd(prefixg[l], prefixg[r]);
             l++;
             r--;
         }
        return ts;
    }
};