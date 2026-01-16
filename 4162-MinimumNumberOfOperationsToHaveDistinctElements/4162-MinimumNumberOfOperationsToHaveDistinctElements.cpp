// Last updated: 1/16/2026, 8:19:42 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i;

        for (i = n - 1; i >= 0; i--) {
            if (st.count(nums[i])) {
                break;
            }
            st.insert(nums[i]);
        }

        if (i == -1) return 0;

        int rem = i + 1;
        return (rem + 2) / 3; 
    }
};
