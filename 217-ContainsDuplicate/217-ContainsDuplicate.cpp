// Last updated: 1/16/2026, 8:21:15 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map <int , bool> m;
        for(auto i: nums){
            if(m[i]) return true;
            else{
                m[i] = true;
            }
        }
        return false;
    }
};