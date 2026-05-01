// Last updated: 5/1/2026, 10:31:01 PM
1class Solution {
2public:
3    void dfs(int r, int c, int oldcol, int newcol, vector<vector<int>>& image) {
4        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
5            image[r][c] != oldcol) {
6                return ;
7        }
8        image[r][c] = newcol;
9
10        dfs(r+1, c , oldcol, newcol, image); // down
11        dfs(r-1, c , oldcol, newcol, image); // up
12        dfs(r, c+1 , oldcol, newcol, image); // right
13        dfs(r, c-1 , oldcol, newcol, image); // left
14    }
15    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
16        int oldcol = image[sr][sc];
17        if(oldcol != color ){
18            dfs(sr, sc, oldcol,color, image);
19        }
20        return image;
21    }
22};