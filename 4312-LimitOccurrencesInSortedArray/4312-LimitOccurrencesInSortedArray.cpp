// Last updated: 5/24/2026, 9:56:25 AM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int cnt = 0;
        for(int i =0 ; i < nums.size(); i++){
            if( i ==0 || nums[i]!= nums[i-1]) cnt = 1;
            else cnt++;
            if (cnt<=k ){
                ans.push_back(nums[i]);
            }
            
        }
        return ans;
    }
};