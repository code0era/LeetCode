// Last updated: 1/16/2026, 8:22:07 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int floorVal = -1, ceilVal = -1;

        // -------- Find Ceil --------
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= target) {
                if(nums[m] == target){ceilVal = m;}
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        // -------- Find Floor --------
        l = 0; h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= target) {
                if(nums[m] == target){floorVal = m;}
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return { ceilVal,floorVal};
    }
};


/*
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int floorVal = -1, ceilVal = -1;

        // -------- Find Ceil --------
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= x) {
                ceilVal = nums[m];
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        // -------- Find Floor --------
        l = 0; h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= x) {
                floorVal = nums[m];
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return {floorVal, ceilVal};
    }
};

*/