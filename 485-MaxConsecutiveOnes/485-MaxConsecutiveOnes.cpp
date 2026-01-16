// Last updated: 1/16/2026, 8:21:03 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0 ;
        int n = nums.size();
        int max1 = 0;
        for(int i = 0 ;i <n; i++){
            if(nums[i]==1){
                cnt++;
                max1 = max(cnt, max1);
            }
            else(cnt = 0);
        }
        return max1;
    }
};