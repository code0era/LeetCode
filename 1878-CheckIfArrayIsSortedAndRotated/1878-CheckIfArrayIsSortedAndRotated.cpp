// Last updated: 5/24/2026, 9:59:32 AM
class Solution {
public:

    bool check(vector<int>& nums) {

        int n = nums.size();

        int breaks = 0;

        for(int i = 0; i < n; i++) {

            // circular next element
            if(nums[i] > nums[(i+1)%n]) {
                breaks++;
            }
        }

        return breaks <= 1;
    }
};