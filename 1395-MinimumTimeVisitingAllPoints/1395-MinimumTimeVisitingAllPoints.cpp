// Last updated: 1/16/2026, 8:20:39 PM
class Solution {
    public:
        int minTimeToVisitAllPoints(vector<vector<int>>& points) {
                int n = points.size();
                        int ans = 0;

                                int i = 0;
                                        int j = 1;

                                                for(int k = 0; k <= n - 1; k++) {
                                                            while(i <= n - 1 && j <= n - 1) {
                                                                            int x = abs(points[i][0] - points[j][0]);
                                                                                            int y = abs(points[i][1] - points[j][1]);

                                                                                                            int mn = min(x, y);
                                                                                                                            int diff = abs(x - y);

                                                                                                                                            ans += mn + diff;

                                                                                                                                                            i++;
                                                                                                                                                                            j++;
                                                                                                                                                                                        }
                                                                                                                                                                                                }

                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                            }
                                                                                                                                                                                                            };
