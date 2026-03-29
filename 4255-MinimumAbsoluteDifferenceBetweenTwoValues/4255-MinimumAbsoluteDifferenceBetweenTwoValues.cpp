// Last updated: 3/29/2026, 8:59:20 AM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int mi  ;
        int res = 1e9;
        for(int i = 0 ; i < nums.size();i++){
            for(int j = i+1; j<nums.size(); j++){
                if((nums[i] ==1 && nums[j] ==2) || nums[i] ==2 && nums[j] ==1){
                     mi = abs(i-j);
                    res = min(res, mi );
                }
            }
        }
        
        return res == 1e9 ?-1:res;
    }
};