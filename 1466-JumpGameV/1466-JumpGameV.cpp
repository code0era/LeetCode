// Last updated: 5/24/2026, 9:59:54 AM
class Solution {
public:

    vector<int> dp ;
    int solve (vector<int >&arr , int d , int i ){
        if(dp[i] != -1 ) return dp[i];
        int  n  = arr.size();
        int ans = 1 ;
        for( int  j  = i +1 ; j<= min( n-1 , i+d); j++){
            if(arr[j] >= arr[i])
            break;
            ans = max(ans ,1+ solve(arr, d ,j));
        }
        for( int  j  = i-1 ; j >=max(0, i-d); j--){
            if(arr[j] >= arr[i])
            break;
            ans = max(ans ,1+ solve(arr, d ,j));
        }

        return dp[ i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int  n = arr.size();
         dp.resize(n,-1);
         int ans =1 ;
         for( int i =0 ; i<n ; i++){
            ans = max(ans, solve(arr, d, i));
         }
         return ans;
    }
};