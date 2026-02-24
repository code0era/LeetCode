// Last updated: 2/24/2026, 10:55:22 AM
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        long long a = 0 , b=0 ;
        bool p1 = true;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] &1) p1 = !p1;
            if((i+1)% 6 == 0) p1 = !p1;;
            p1?a+=nums[i] :b += nums[i];
        }
        return a-b;
    }
};