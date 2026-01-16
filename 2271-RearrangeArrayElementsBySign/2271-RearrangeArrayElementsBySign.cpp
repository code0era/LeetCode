// Last updated: 1/16/2026, 8:20:19 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> p, ans(s);
        int id = 0;
        int idd = 1;
        vector<int> n;
        for (auto it : nums) {
            if (it > 0) {
                ans[id] =it;
                id+=2;
                
            } else if (it < 0) {
                ans[idd] =it;
                idd+=2;    
            }
        } 
        return ans;
    }
};