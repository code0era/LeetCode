// Last updated: 6/14/2026, 9:38:07 AM
class Solution {
public:

    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();

        int currLen = 1;

        int maxLen =1;

        for(int i = 1; i < n; i++) {

            if(nums[i] > nums[i - 1]) {

                currLen++;
            }
            else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};