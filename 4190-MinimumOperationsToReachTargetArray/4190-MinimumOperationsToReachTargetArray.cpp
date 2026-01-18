// Last updated: 1/18/2026, 2:20:34 PM
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int ans = 0 ;
        unordered_map<int, vector<int>>pos;
        for(int i =0 ; i <n ; i++){
            pos[nums[i]].push_back(i);  
        }
        vector<bool> done(n ,false);
        for(int i =0; i<n ; i++){
            if(done[i]|| nums[i]==target[i]) continue;
            int x = nums[i];
            for(int j : pos[x]){
                if(!done[j]&& nums[j] == x){
                    nums[j] = target[j];
                    done[j]= true;
                }
            }
            ans++;
        }
        return ans;
    }
};