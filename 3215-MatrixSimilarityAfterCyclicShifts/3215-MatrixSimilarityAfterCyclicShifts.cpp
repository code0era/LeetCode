// Last updated: 3/28/2026, 1:28:48 AM
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for(auto & row: mat){
            for(int j = 0; j< n ; ++j){
                if(row[j]!=row[(j+k)%n])
                    return false;
            }
        }
        return true;
    }

};