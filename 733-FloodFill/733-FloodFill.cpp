// Last updated: 6/14/2026, 9:38:03 AM
class Solution {
public:
    void dfs(int r, int c, int oldcol, int newcol, vector<vector<int>>& image) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
            image[r][c] != oldcol) {
                return ;
        }
        image[r][c] = newcol;

        dfs(r+1, c , oldcol, newcol, image); // down
        dfs(r-1, c , oldcol, newcol, image); // up
        dfs(r, c+1 , oldcol, newcol, image); // right
        dfs(r, c-1 , oldcol, newcol, image); // left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int oldcol = image[sr][sc];
        if(oldcol != color ){
            dfs(sr, sc, oldcol,color, image);
        }
        return image;
    }
};