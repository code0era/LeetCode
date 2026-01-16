// Last updated: 1/16/2026, 8:20:26 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0 ; 
         int h =  n -1 ;
        while(l <= h ){
            int m =  (l+h ) / 2;
            int mss =  arr[m] - m-1;
            if(mss < k){
                l =  m+1;
            }
            else{
                h = m-1;
            }
        }
        return k + h +1;
    }
}; 