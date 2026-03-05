// Last updated: 3/5/2026, 5:55:12 AM
#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);
        
        // 1. Record the count of 1s in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int specialPositions = 0;
        
        // 2. Check each cell; if it's 1 and its row/col counts are 1, it's special
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    specialPositions++;
                }
            }
        }
        
        return specialPositions;
    }
};