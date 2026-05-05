// Last updated: 5/5/2026, 9:13:52 PM
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j]) {
                    // Start DFS for each unvisited cell
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int r, int c, int pr, int pc, char target) {
        
        visited[r][c] = true;
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check boundaries and character match
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == target) {
                if (visited[nr][nc]) {
                    // If visited and not the parent, a cycle exists
                    if (nr != pr || nc != pc) {
                        return true;
                    }
                } else {
                    // Recursive DFS call
                    if (dfs(grid, visited, nr, nc, r, c, target)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};