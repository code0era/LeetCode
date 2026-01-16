// Last updated: 1/16/2026, 8:20:55 PM
class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        // Center must be 5
        if (g[r+1][c+1] != 5) return false;

        vector<bool> seen(10, false);

        // Check numbers are 1 to 9 and distinct
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                int val = g[i][j];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        int sum = g[r][c] + g[r][c+1] + g[r][c+2];

        // Rows
        for (int i = r; i < r+3; i++) {
            if (g[i][c] + g[i][c+1] + g[i][c+2] != sum)
                return false;
        }

        // Columns
        for (int j = c; j < c+3; j++) {
            if (g[r][j] + g[r+1][j] + g[r+2][j] != sum)
                return false;
        }

        // Diagonals
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;

        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
