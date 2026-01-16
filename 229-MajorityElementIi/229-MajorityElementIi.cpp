// Last updated: 1/16/2026, 8:21:12 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int e1 = INT_MIN;
        int e2 = INT_MIN;
        int s = nums.size();

        for (int i = 0; i < s; i++) {
            if (nums[i] == e1) {
                c1++;
            }
            else if (nums[i] == e2) {
                c2++;
            }
            else if (c1 == 0) {
                e1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0) {
                e2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        vector<int> ls;
        int cn1 = 0;
        int cn2 = 0;

        for (int i = 0; i < s; i++) {
            if (nums[i] == e1) {
                cn1++;
            }
            if (nums[i] == e2) {
                cn2++;
            }
        }

        if (cn1 > s / 3) {
            ls.push_back(e1);
        }
        if (cn2 > s / 3) {
            ls.push_back(e2);
        }

        return ls;
    }
};
//   the array must have the 2 elements whose freq > n/3