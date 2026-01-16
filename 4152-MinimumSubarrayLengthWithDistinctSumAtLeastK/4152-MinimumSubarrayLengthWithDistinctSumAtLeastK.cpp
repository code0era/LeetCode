// Last updated: 1/16/2026, 8:19:44 PM
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
       unordered_map<int, int> m;
        int l = 0 ;
        int s = 0 ;
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i <n ; i++){
            if(m[nums[i]]== 0){
                s+=nums[i];
            }
            m[nums[i]]++;
            while(s>=k){
                ans = min(ans, i -l +1); // Length;
                //  Now shrink
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    s -=nums[l];
                }
                l++;
                
            }
        }
        return ans  == INT_MAX ? -1 :ans;
    }
};