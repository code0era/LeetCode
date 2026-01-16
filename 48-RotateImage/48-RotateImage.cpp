// Last updated: 1/16/2026, 8:22:03 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int  r = matrix.size();
        int c = matrix[0].size();
        // transpose
        for(int i = 0 ; i < r-1; i++){
            for(int j = i+1 ; j <c; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        // reversing the row 
         for (int i = 0; i < r; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};