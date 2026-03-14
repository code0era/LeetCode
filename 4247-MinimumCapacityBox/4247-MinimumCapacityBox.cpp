// Last updated: 3/14/2026, 9:03:56 PM
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ind = -1,val = 1e9;
        for( int i = 0 ; i < capacity.size(); i++){
            if(itemSize<=capacity[i] && capacity[i] < val){
                val = capacity[i];
                ind = i;
                
                
            }
        }
        return ind;
    }
};