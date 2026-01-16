// Last updated: 1/16/2026, 8:20:47 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto i : nums){
            freq[i]++;
        }

        for(auto i : freq){
            if(i.second >= nums.size()/2 )
            return i.first;
        }
        return -1;
    }
};