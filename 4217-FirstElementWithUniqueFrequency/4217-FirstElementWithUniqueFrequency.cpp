// Last updated: 2/15/2026, 12:35:47 PM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int , int > freq;
        for(int x : nums)freq[x]++;
        unordered_map<int , int > countF;
        for(auto &p :freq){
            countF[p.second]++;
        }
        for(int x :nums) {
            int f = freq[x];
            
            if (countF[f]==1){
                return x;
            }
        }
        return -1;
    }
};