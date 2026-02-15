// Last updated: 2/15/2026, 9:22:18 AM
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // We create a 101x101 grid (max constraints are 100)
        // Using double because we are dealing with fractions
        double tower[101][101] = {0.0};
        
        // Pour everything into the first glass
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                // If the current glass overflows
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                    
                    // Optional: Cap the current glass at 1.0, 
                    // though not strictly necessary for the math to work for rows below.
                    tower[r][c] = 1.0;
                }
            }
        }
        
        // The result is the amount in the specific glass, capped at 1.0
        return min(1.0, tower[query_row][query_glass]);
    }
};