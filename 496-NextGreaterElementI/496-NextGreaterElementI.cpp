// Last updated: 3/4/2026, 4:52:11 AM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        vector<int> st;
        st.reserve(nums2.size());

        for (int x : nums2) {
            while (!st.empty() && st.back() < x) {
                nge[st.back()] = x;
                st.pop_back();
            }
            st.push_back(x);
        }

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) {
            auto it = nge.find(x);
            ans.push_back(it == nge.end() ? -1 : it->second);
        }
        return ans;
    }
};