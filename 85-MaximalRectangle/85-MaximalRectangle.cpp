// Last updated: 1/16/2026, 8:21:50 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxA = 0;
        h.push_back(0); // sentinel

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        h.pop_back();
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < n; j++) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};
