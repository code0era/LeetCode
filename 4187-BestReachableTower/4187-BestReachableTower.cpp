// Last updated: 1/18/2026, 2:20:30 PM
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> b = {-1, -1};
         int m = -1;
        for(auto & v: towers)
            if(abs(v[0] -center[0])+abs(v[1]- center[1])<= radius){
                vector<int> p = {v[0] , v[1]};
                if(v[2]> m || (v[2] == m &&  p<b)) m = v[2], b = p;
            }
            return b ;
        
    }
};