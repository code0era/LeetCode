// Last updated: 1/16/2026, 8:19:47 PM
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n  = nums.size();
        int c = 0 ;
        for(int i = 0 ;   i < n ; i++){
            int s = 0 ;
            unordered_set<int> st;
            for(int j = i ;  j < n ; j++){
                s += nums[j];
                st.insert(nums[j]);
                if(st.count(s)){
                    c++;
                }
            }
        }
        return c;
    }
};