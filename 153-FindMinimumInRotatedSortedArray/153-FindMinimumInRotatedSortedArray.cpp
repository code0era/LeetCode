// Last updated: 1/16/2026, 8:21:23 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = INT_MAX;
        int h = n - 1;
        int id = -1;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[l] <= nums[h]) {
                if (nums[l] < ans) {
                    id = l;
                    ans = nums[l];
                }
                break;
            }
            if (nums[l] <= nums[mid]) {
                if (nums[l] < ans) {
                    id = l;
                    ans = nums[l];
                }
                l = mid + 1;
            } else {
                 if(nums[mid]<ans){
                    id = mid ;
                    ans = nums[mid];
                }
                h = mid - 1;
            }
        }
        return ans;
    }
};