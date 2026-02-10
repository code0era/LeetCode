// Last updated: 2/11/2026, 12:52:48 AM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        long long t = 0 ;
        for(int x : nums) t +=x;
        int a = 0 ;
        for(int i = 0 ; i < n ; i++){
            t-=nums[i];
            int c = n-i-1;
            if(c == 0 ) continue;
            if((long long )nums[i]* c > t)a++;
        }
        return a;
    }
};