// Last updated: 1/16/2026, 8:20:05 PM
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int > a (n ,INT_MAX);
        a[0] = 0;
        // applying positional restriction
        for(auto i : restrictions){
            int id = i[0];
            int v = i[1];
            a[id] = min(a[id] , v);
        }
        // Left to right check
        for(int i  =  1 ; i < n ; i++){
            a[i] = min(a[i], a[i-1]+ diff[i-1]);
        }
        // right to left check
        for(int i  = n-2 ; i >=0 ; i--){
            a[i] = min(a[i], a[i+1]+ diff[i]);
        }

        // Max value:::
        int ans = 0 ;
        for(auto x:a){
            ans = max(ans , x);
        }
        return ans;
    }
};