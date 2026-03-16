// Last updated: 3/16/2026, 11:10:43 PM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> count;
         for(int x : nums) count[x]++;
        for( int x : nums ){
            if(x%2 == 0 && count[x] ==1) return x;
        }
        return -1;
    }
};