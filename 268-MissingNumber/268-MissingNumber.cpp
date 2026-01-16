// Last updated: 1/16/2026, 8:21:10 PM
// XOR approach


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0 ; i<n ;i++){
            xor1^=i;
            xor2^=nums[i];

        }
        xor1= xor1^n;
        return xor1^xor2; 
        
    }
};



// // sum  Approach
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n =nums.size();
//         int sumN = (n*(n+1))/2;
//         int sum=0 ;
//         for(auto it:nums){
//             sum+=it;
//         }
//         return sumN-sum;
        
//     }
// };


// Hash approach: tc: o(n)+o(n) => o(n)  
 
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n =nums.size();
//         vector<int> hash(n+1,0);
//         for(auto it:nums){
//             hash[it]=1;
//         }
//         for(int i = 0;i<n+1;i++){
//             if(hash[i]==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };