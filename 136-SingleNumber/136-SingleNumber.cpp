// Last updated: 1/16/2026, 8:21:27 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        for(int i = 0 ; i< n ; i++){
            xor1^=nums[i];
        }
        return xor1;
    }
};