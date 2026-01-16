// Last updated: 1/16/2026, 8:21:29 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        int ans = 1;
        unordered_set<int>st ;
        for(int i = 0 ; i <n ; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) ==st.end()){
                int c = 1 ;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x++;
                    c++;
                }
                ans = max (ans , c);
            }
        }
        return ans ;
    }
};