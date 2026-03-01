// Last updated: 3/1/2026, 9:33:52 AM
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int , int> f;
        for(int x : nums){
            f[x]++;
        }
        vector<int> v;
        for( auto  &p : f){
            v.push_back(p.first);
        }
        sort( v.begin() , v.end());
        for(int i = 0 ; i < v.size() ; i++ ){
            for(int j = i +1 ; j < v.size() ; j++ ){
                if(f[v[i]]!= f[v[j]]){
                    return {v[i] , v[j]};
                }
            }
        }
        return {-1 , -1};
    }
};