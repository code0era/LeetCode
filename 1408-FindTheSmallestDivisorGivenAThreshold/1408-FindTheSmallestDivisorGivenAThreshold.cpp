// Last updated: 1/16/2026, 8:20:38 PM
class Solution {
public:

    long long  value(vector<int>& nums, int k ){
        long v = 0 ;
for(int i = 0 ; i < nums.size(); i++){
v += (nums[i] + k - 1) / k;
}
return v ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx =INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            mx = max(mx , nums[i]);
        }
        int l = 1 ;
        int h = mx;
        while(l<=h){
            int mid = l +( h-l)/2;
            if(value(nums , mid) <= threshold ){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;





    }
};