// Last updated: 1/16/2026, 8:22:13 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int id = 0;
        for (auto it : st) {
            nums[id] = it;
            id++;
        }
        int k = st.size();
        return k; 
    }
};