// Last updated: 1/16/2026, 8:22:01 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       long long sum =  INT_MIN ;
       long long  maxSum = INT_MIN;
    for(auto it: nums){
        sum = max((long long)it, sum+it);
        maxSum = max(sum,maxSum);
    }
  

    return maxSum;
    }
    
};