// Last updated: 1/16/2026, 8:21:04 PM
class Solution {
public:
int posStudNo(vector<int> &nums, int pages) {
        int stud = 1;
        long long pg = 0;

        for (auto it : nums) {
            if (pg + it <= pages) {
                pg += it;
            } else {
                stud++;
                pg = it;
            }
        }
        return stud;
    }
    int splitArray(vector<int>& nums, int k) {
         if (k > nums.size()) return -1;
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
         int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            int st = posStudNo(nums, mid);

            if (st > k) {
                l = mid + 1;
            } else {
                ans = mid;     // store possible answer
                h = mid - 1;
            }
        }
        return ans;
    }
};

 /// Similiar to book allocation problem
/*
class Solution {
public:

    int posStudNo(vector<int> &nums, int pages) {
        int stud = 1;
        long long pg = 0;

        for (auto it : nums) {
            if (pg + it <= pages) {
                pg += it;
            } else {
                stud++;
                pg = it;
            }
        }
        return stud;
    }

    int findPages(vector<int> &nums, int m) {
        if (m > nums.size()) return -1;

        // ❌ wrong in your code, corrected here
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            int st = posStudNo(nums, mid);

            if (st > m) {
                l = mid + 1;
            } else {
                ans = mid;     // store possible answer
                h = mid - 1;
            }
        }
        return ans;
    }
};

*/