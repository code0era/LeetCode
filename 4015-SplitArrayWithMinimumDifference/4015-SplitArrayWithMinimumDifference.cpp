// Last updated: 1/16/2026, 8:19:58 PM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return -1;
        vector<long long> P(n, 0);
        P[0] = nums[0];
        for (int i = 1; i < n; ++i)
            P[i] = P[i - 1] + nums[i];
        vector<bool> D(n, true);
        for (int i = n-2; i >=0 ; --i) {
            D[i] = (nums[i] > nums[i + 1]) && D[i + 1];
            
        }
        vector<bool> I(n, true);
        for (int i = 1; i <n ; ++i) {
            I[i] = (nums[i] > nums[i - 1]) && I[i - 1];
            
        }
        long long min_diff = -1;
        for(int i = 0 ; i < n-1 ; ++i){
            if(I[i] && D[i+1]){
                long long L = P[i];
                long long R = P[n-1] -L;
                long long CD = abs(L-R);
                if(min_diff == -1 ||  CD<min_diff) min_diff = CD;
                
            }
        }
        return min_diff;
    }
};