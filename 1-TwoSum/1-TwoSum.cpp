// Last updated: 1/16/2026, 8:22:29 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int > mapp;
        for( int i = 0 ; i < n ; i ++){
            int  t = target - nums[i];
            if(mapp.count(t)){
                return {mapp[t], i };
            }
            mapp[nums[i]] = i;
        }
        return {};
    }
};