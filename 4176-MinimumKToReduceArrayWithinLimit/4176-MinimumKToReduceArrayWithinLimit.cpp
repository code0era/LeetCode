// Last updated: 1/31/2026, 9:34:04 PM
class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long l =1 ,r = 1e5, n = nums.size();
        while(l<r){
            long long m = (l+r)/2,s =0;
            for(int x : nums){
                s+=(x+m-1)/m;
                if(s>m*m)break;
            }
            if(s<=m*m) r = m ;
            else l = m+1;
        
        }
        return l;
    }
};