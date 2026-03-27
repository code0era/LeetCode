// Last updated: 3/28/2026, 1:27:19 AM
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minval = *min_element(nums1.begin(), nums1.end());
        int odd = 0 , even = 0;
        for(int x: nums1){
            if(x%2) odd++;
            else even++;
        }
        if(odd == 0 || even ==0) return true;
        return(minval%2==1);
    }
};