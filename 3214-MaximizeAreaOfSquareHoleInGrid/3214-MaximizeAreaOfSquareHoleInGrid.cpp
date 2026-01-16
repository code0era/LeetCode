// Last updated: 1/16/2026, 8:20:15 PM
class Solution {
public:
    int maC(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int m = 1;
        int c = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                c++;
            } else {
                c = 1;
            }
            m = max(m, c);
        }
        return m;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars ,vector<int>& vBars) {
        int H  = maC(hBars);
        int V  = maC(vBars);
        int ss = min(H, V)+1;

        return  ss*ss;
    }
};
