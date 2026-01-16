// Last updated: 1/16/2026, 8:22:06 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int  n = nums.size();
        int l = 0 ;
        int h = n-1;
        int ans=  n ;
        while(l<=h){
            int m = (l+h )/2;
            if(nums[m] >= target){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;      
    }
};