// Last updated: 5/24/2026, 9:57:01 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int  n = nums.size() , a = 1 , d = 1 , x =0 , ans =1e9;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] ==0 ) x =i;
            if(nums[(i+1)%n]!= (nums[i]+1)%n) a = 0 ;
            if(nums[(i+1)%n]!= (nums[i]-1+n)%n) d = 0 ;
        }
        if(a) ans = min(x, n-x+2);
        if(d) ans = min({ans , n-x, (x+1)%n +1});
        return ans == 1e9? -1 : ans;
    }
};