// Last updated: 1/21/2026, 3:20:45 PM
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> row(m, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i][j+1] = row[i][j] + grid[i][j];
                col[i+1][j] = col[i][j] + grid[i][j];
            }
        }

        for(int k = min(m, n); k >= 2; k--) {
            for(int i = 0; i + k <= m; i++) {
                for(int j = 0; j + k <= n; j++) {
                    
                    int sum = row[i][j+k] - row[i][j];
                    bool ok = true;

                    for(int x = 0; x < k; x++) {
                        if(row[i+x][j+k] - row[i+x][j] != sum ||
                           col[i+k][j+x] - col[i][j+x] != sum) {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) continue;

                    int d1 = 0, d2 = 0;
                    for(int x = 0; x < k; x++) {
                        d1 += grid[i+x][j+x];
                        d2 += grid[i+x][j+k-1-x];
                    }

                    if(d1 == sum && d2 == sum) return k;
                }
            }
        }

        return 1;
    }
};
