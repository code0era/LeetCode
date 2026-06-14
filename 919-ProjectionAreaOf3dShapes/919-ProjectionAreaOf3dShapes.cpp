// Last updated: 6/14/2026, 9:37:48 AM
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int i = 0; i < n; i++) {
            int rowMax = 0, colMax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) res++;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            res += rowMax + colMax;
        }
        return res;
    }
};